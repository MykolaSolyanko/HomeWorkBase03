#include <bitset>
#include <iostream>

int sum_and_avrg() {
  int sum{};
  int d_amnt{};
  int num{};
  std::cin >> num;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
    d_amnt++;
  }

  std::cout << sum << std::endl;
  std::cout << (double)(sum / d_amnt) << std::endl;

  return 0;
}

int lucky_tckt() {
  int num{};
  std::cin >> num;
  int six_dig_bndr = 100000;
  if (num < six_dig_bndr) {
    std::cout << "Incorrect typed number" << std::endl;
    return 0;
  }
  int frst_prt{num % 1000}; // get last 3 digits
  int f_sum{};

  while (frst_prt > 0) {
    f_sum += frst_prt % 10;
    frst_prt /= 10;
  }

  num /= 1000; // cut source number to first 3 digits
  int scnd_prt{num};
  int s_sum{};

  while (scnd_prt > 0) {
    s_sum += scnd_prt % 10;
    scnd_prt /= 10;
  }

  bool lucky{(f_sum == s_sum)};
  std::cout << "Is the ticket lucky "
            << "- " << std::boolalpha << lucky << std::endl;

  return 0;
}

int reverse_num() {
  int32_t num{};
  std::cin >> num;
  int res{};
  int coeff{100};

  while (num) {
    res += (num % 10) * coeff;
    num /= 10;
    coeff /= 10;
  }

  std::cout << res << std::endl;

  return 0;
}

int sum_odd_nmbrs() {
  int lwr_inpt{1};
  int uppr_inpt{50};
  int lwr_rng{-60};
  int uppr_rng{90};
  int sum{};

  for (int i = lwr_inpt; i <= uppr_inpt; i++) {
    int num{};
    std::cin >> num;
    if ((num >= lwr_rng) && (num <= uppr_rng)) {
      if (num & 1) { // bitwise check if number is odd
        sum += num;
      }
    } else {
      std::cout << num << " is out of range " << lwr_rng << ".." << uppr_rng
                << std::endl;
    }
  }

  std::cout << "Sum is " << sum << std::endl;

  return 0;
}

int best_divider() {
  int num{};
  std::cin >> num;
  int max_best{};
  int count{num};
  while (--count > 0) { // find the biggest divider in reverse order
    if ((num % count) == 0) {
      max_best = count;
      break;
    }
  }

  std::cout << max_best << std::endl;
  return 0;
}

int build_tree() {
  int num{};
  std::cin >> num;

  if (!(num & 1)) { // bitwise check if number is even number
    num += 1;
  }
  int mdl = num / 2;
  int l_brdr{mdl}; // initialize left and right borders middle num
  int r_brdr{mdl};
  char astrsk{'*'};
  char spc{' '};
  for (int i = 0; i < num; i += 2) {
    for (int j = 0; j <= num; j++) {
      if ((j >= l_brdr) && (j <= r_brdr)) {
        std::cout << astrsk;
      } else {
        std::cout << spc;
      }
    }
    std::cout << std::endl;
    l_brdr -= 1;
    r_brdr += 1;
  }

  return 0;
}

int count_bits() {
  int num{};
  std::cin >> num;
  int count{};
  while (num > 0) {
    count += num % 2;
    num /= 2;
  }
  std::cout << "Set bits are " << count << std::endl;
  return 0;
}

int is_bit_set() {
  int num{};
  int ordr{};
  std::cin >> num >> ordr;
  ordr -= 1;
  if (num & (1 << ordr)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}

int build_num() {
  int amnt{};
  std::cin >> amnt;
  int sum{};
  while (amnt) {
    int tmp{};
    std::cin >> tmp;
    while (tmp) {
      sum += tmp % 10;
      tmp /= 10;
    }
    --amnt;
  }

  if (sum % 3 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
int main() {
  // sum_and_avrg();
  // lucky_tckt();
  // reverse_num();
  // sum_odd_nmbrs();
  // best_divider();
  // build_tree();
  // count_bits();
  // is_bit_set();
  // build_num();
  return 0;
}