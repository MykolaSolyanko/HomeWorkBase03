#include <cmath>
#include <cstring>
#include <iostream>
#include <random>

/**
 * @brief Define size of encoded message
 *
 */
static constexpr size_t MSG_SIZE{1024};

/**
 * @brief Define size of key table
 *
 */
constexpr uint32_t TABLE_SIZE{6};

/**
 * @brief Key table for encoding via Feistel algorithm
 *
 */
uint8_t key_table[TABLE_SIZE]{123, 143, 31, 145, 45, 141};

/**
 * @brief A structure to emulate data exchange via serial interface
 *
 */
struct data_t {
  /*size of bytes to rx/tx*/
  size_t size;
  /*data buffer*/
  char data[MSG_SIZE];
};

/**
 * @brief The key which opens messaging session
 *
 */
struct crypto_t {
  size_t col;
  size_t row;
};

/*A key which generates Alisa*/
static crypto_t Alisa_crypto{};

/*Encoded data to send via serial interface*/
static data_t Alisa_enc_message{};

/*A message which sends Alisa to Bob*/
char Message[MSG_SIZE]{"The first half of life consists of the capacity to "
                       "enjoy without the chance, the last half consists of "
                       "the chance without the capacity. Mark Twain"};

/*The key which Bob reseives from Alisa to decode message*/
static crypto_t Bob_crypto{};

/*Encoded data to */
static data_t Bob_enc_message{};

/*Encoded data which Bob reseives from Alisa via sereal interfase*/
static char Bob_dec_message[MSG_SIZE]{};

/**
 * @brief                   Magic function for encoding data through Feistel
 * rounds
 *
 * @param subblock    [i]   Subbloc on data for encoding
 * @param key         [i]   A Secret key
 * @return uint8_t          Encoded data
 */
static uint8_t f(uint8_t subblock, uint8_t key) { return pow(key, subblock); }

/**
 * @brief          This function encode data via Feistel algorithm
 *
 * @param left     [i/o]  Pointer to hight(left) byte for selected two bytes
 *                        frame
 * @param right    [i/o]  Pointer to low(right) byte for selected two bytes
 *                        frame
 * @param rounds   [i]    Rounds quantity
 * @param key      [i]    Pointer to key data table
 */
static void feistel_crypt(uint8_t *left, uint8_t *right, uint32_t rounds,
                          uint8_t *key) {
  for (uint32_t i = 0; i < rounds; i++) {
    uint8_t temp = *right ^ f(*left, key[i]);
    *right = *left;
    *left = temp;
  }
}

/**
 * @brief          This function decryptes data via Feistel algorithm
 *
 * @param left     [i/o]  Pointer to hight(left) byte for selected two bytes
 * frame
 * @param right    [i/o]  Pointer to low(right) byte for selected two bytes
 * frame
 * @param rounds   [i]    Rounds quantity
 * @param key      [i]    Pointer to key data table
 */
static void feistel_decrypt(uint8_t *left, uint8_t *right, uint32_t rounds,
                            uint8_t *key) {
  uint32_t i = rounds - 1;
  do {
    uint8_t temp = *left ^ f(*right, key[i]);
    *left = *right;
    *right = temp;
  } while (i--);
}

/**
 * @brief          Function to print encoded table
 *
 * @param data     [i] Pointer to data for printing
 * @param crypto   [i] Key to define a table
 */
static void crypto_print(const char *data, crypto_t crypto) {
  for (size_t iRow = 0; iRow < crypto.row; iRow++) {
    std::cout << "ROW: " << iRow << " ";
    for (size_t iCol = 0; iCol < crypto.col; iCol++) {
      std::cout << *(data + iRow * crypto.col + iCol) << '\t';
    }
    std::cout << std::endl;
  }
}

/**
 * @brief            This function writes the message in columns
 *
 * @param dstr       [i/o]  Pointer to external data
 * @param crypto     [i]    The key defines size of table
 * @param src        [i/o]  Pointer to message for encoding
 */
static void crypto_write_cols(data_t *dstr, const crypto_t crypto,
                              const char *src) {
  if ((dstr == nullptr) || (src == nullptr)) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  dstr->size = 0;
  for (size_t iCol = 0; iCol < crypto.col; iCol++) {
    for (size_t iRow = 0; iRow < crypto.row; iRow++) {
      *(dstr->data + iRow * crypto.col + iCol) = *src;
      if (*src == '\0') {
        return;
      }
      src++;
      dstr->size++;
    }
  }
}

/**
 * @brief            This function reads the message by columns
 *
 * @param src        [i]    Pointer to external data
 * @param crypto     [i]    The key defines size of table
 * @param dstr       [i/o]  Pointer to buffer where decoded data will be written
 */
static void crypto_read_cols(const data_t *src, const crypto_t crypto,
                             char *dstr) {
  if ((dstr == nullptr) || (src == nullptr) ||
      (src->size != (crypto.row * crypto.col))) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  size_t index{};
  for (size_t iCol = 0; iCol < crypto.col; iCol++) {
    for (size_t iRow = 0; iRow < crypto.row; iRow++) {
      dstr[index++] = *(src->data + iRow * crypto.col + iCol);
    }
  }
  std::cout << std::endl;
}

/**
 * @brief          This function calculates string lenght
 *
 * @param msg      [i] Pointer to string
 * @return size_t      Size of string
 */
static size_t msg_len(const char *msg) {
  size_t len{};
  while ((msg != nullptr) && (*msg != '\0')) {
    len++;
    msg++;
  }
  return len;
}

/**
 * @brief           This function generates random uint32_t value
 *
 * @param MIN         [i]  Minimal value in random distribution
 * @param MAX         [i]  Maximal value in random distribution
 * @return uint32_t        Random value
 */
static uint32_t rand_uint32(uint32_t MIN, uint32_t MAX) {
  // Will be used to obtain a seed for the random number engine
  std::random_device rd;
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<uint32_t> distrib(MIN, MAX);
  // Use `distrib` to transform the random unsigned int generated by gen into
  // an int in [MIN, MAX]
  return distrib(gen);
}

/**
 * @brief         This function calculates the best devider for given value
 *
 * @param value     [i] value for processing
 * @return size_t       devider
 */
static size_t best_devider(size_t value) {
  auto devider{value};
  while ((devider != 1) && (value % (--devider))) {
  }
  return devider;
}

/**
 * @brief          This function counts all deviders for given value
 *
 * @param value    [i] Value to process
 * @return size_t      Quantity of deveders
 */
static size_t devider_quantity(size_t value) {
  size_t quantity{1};
  while ((value = best_devider(value)) != 1) {
    std::cout << "Devider is: " << value << std::endl;
    quantity++;
  }
  return quantity;
}

/**
 * @brief         This function generates an encrption key
 *
 * @param crypto    [i/o] Pointer to key structure
 * @param message   [i]   Pointer to message
 */
static void ALISA_crypto_key_init(crypto_t *crypto, const char *message) {
  if ((crypto == nullptr) || (message == nullptr)) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  /*Calculate message len*/
  auto len{msg_len(message)};
  /*All possible divisors of the number are calculated, and then one of them is
   * randomly selected (Except 1)*/
  crypto->col = len;
  for (size_t rand_x = rand_uint32(1, devider_quantity(crypto->col) - 1);
       rand_x; rand_x--) {
    crypto->col = best_devider(crypto->col);
  }
  /*Calculate rows size*/
  crypto->row = len / crypto->col;
  std::cout << "Message len = " << len << std::endl;
  std::cout << "col = " << crypto->col << std::endl;
  std::cout << "row = " << crypto->row << std::endl;
}

/**
 * @brief             This function encypt the key via Feistel algorithm
 *
 * @param key         [i/o] Pointer to key for encryption
 * @param key_size    [i]   size of key
 */
static void ALISA_crypto_key_encode(void *key, size_t key_size) {
  if ((key == NULL) || (key_size == 0) || (key_size % 2)) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  uint8_t *key_head = (uint8_t *)key;
  for (uint8_t *frame = key_head; frame != (key_head + sizeof(key_size));
       frame += 2) {
    feistel_crypt(frame, frame + 1, 5, key_table);
  }
}

/**
 * @brief              The function encodes the message with a key
 *
 * @param enc_data     [i/o] Pointer where wiil written encoded data
 * @param crypto       [i]   Key for encoding
 * @param message      [i]   Message
 */
static void ALISA_Encode(data_t *enc_data, const crypto_t crypto,
                         const char *message) {
  if ((enc_data == nullptr) || (message == nullptr)) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  crypto_write_cols(enc_data, crypto, message);
}

/**
 * @brief              The function decodes received from Alisa the key to join
 * session
 *
 * @param crypto        [i/o]   The key to decode message
 * @param encoded_data  [i]     Buffer stores encoded key
 */
static void BOB_crypto_key_init(crypto_t *crypto, const data_t *encoded_data) {
  if ((crypto == nullptr) || (encoded_data == nullptr) ||
      (encoded_data->size != sizeof(crypto_t))) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  *crypto = *((crypto_t *)encoded_data->data);
}

static void BOB_crypto_key_decode(void *key, size_t key_size) {
  if ((key == NULL) || (key_size == 0) || (key_size % 2)) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  uint8_t *key_head = (uint8_t *)key;
  for (uint8_t *frame = key_head; frame != (key_head + sizeof(key_size));
       frame += 2) {
    feistel_decrypt(frame, frame + 1, 5, key_table);
  }
}

/**
 * @brief              The function to decode message received from Alisa
 *
 * @param enc_data     [i]   Pointer to encoded data
 * @param crypto       [i]   Tke key to decode the message
 * @param message      [i/o] Pointer to buffer to write decoded message
 */
static void BOB_Decode(const data_t *enc_data, const crypto_t crypto,
                       char *message) {
  if ((enc_data == nullptr) || (message == nullptr) ||
      (enc_data->size != (crypto.col * crypto.row))) {
    std::cout << "ERROR: " << __PRETTY_FUNCTION__ << std::endl;
    return;
  }
  crypto_read_cols(enc_data, crypto, message);
}

/**
 * @brief               This does safety cin operation
 * 
 * @param annotation 
 * @param param 
 * @return true 
 * @return false 
 */
static bool param_init_safety(const char *annotation, char *const param) {
  if ((param == nullptr) || (annotation == nullptr)) {
    return false;
  }
  while (true) {
    std::cout << annotation;
    std::cin >> *param;
    if (!std::cin.fail()) {
      return true;
    }
    std::cin.clear();
    std::cin.ignore();
  }
}

int main() {
  /*Store User's command*/
  char cmd{};

  while ((cmd != 'N') && (cmd != 'n') && (cmd != 'Y') && (cmd != 'y')) {
    std::cout << "Would you like to run program with default message to test?"
              << std::endl;
    param_init_safety("y/n? --> ", &cmd);
  }

  if ((cmd == 'N') || (cmd == 'n')) {
    /*In case if user wanna to input his own string*/
    std::cout << "Alisa, input yours message to Bob : " << std::endl;
    std::cin.ignore();
    std::cin.clear();
    std::cin.getline(Message, MSG_SIZE, '\n');
  } else {
    /*Default test to quick checking*/
    std::cout << "Default message is: " << Message << std::endl;
  }

  /*Stage I - Generate a key to create session with BOB*/
  ALISA_crypto_key_init(&Alisa_crypto, Message);

  /*Write the to buffer for sending via serial interface*/
  Alisa_enc_message.size = sizeof(Alisa_crypto);
  memcpy(Alisa_enc_message.data, &Alisa_crypto, Alisa_enc_message.size);

  /*Encrypt the key via Feistel algorythm*/
  ALISA_crypto_key_encode(Alisa_enc_message.data, Alisa_enc_message.size);

  /*Sending the key to BOB via serial interface*/
  Bob_enc_message.size = Alisa_enc_message.size;
  memcpy(Bob_enc_message.data, Alisa_enc_message.data, Alisa_enc_message.size);

  /*Decoding a secret key on BOB's side via Feistel alogorythm*/
  BOB_crypto_key_decode(Bob_enc_message.data, Bob_enc_message.size);

  /*Init secret key to start data exchange session with ALISA*/
  BOB_crypto_key_init(&Bob_crypto, &Bob_enc_message);

  /*Stage II - Alisa encryption of a message with a secret key*/
  ALISA_Encode(&Alisa_enc_message, Alisa_crypto, Message);

  /*Print encoded message*/
  crypto_print(Alisa_enc_message.data, Alisa_crypto);

  /*Sending encoded message to BOB via serial interface*/
  Bob_enc_message.size = Alisa_enc_message.size;
  memcpy(Bob_enc_message.data, Alisa_enc_message.data, Alisa_enc_message.size);

  /*Bob decodes the message with secret key*/
  BOB_Decode(&Bob_enc_message, Bob_crypto, Bob_dec_message);
  /*Printing the message*/
  std::cout << "Decoded message is: " << Bob_dec_message << std::endl;
  return EXIT_SUCCESS;
}
