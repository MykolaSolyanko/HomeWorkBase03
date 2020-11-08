#include <bitset>
#include <iostream>

int sum_and_avrg() {
    int sum{};
    int d_amnt{};
    int num{};
    std::cout << "Type a number: ";
    std::cin >> num;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
        d_amnt++;
    }

    std::cout << "Sum of digits is " << sum << std::endl;
    std::cout << "Average value is " << static_cast<double>(sum) / d_amnt
        << std::endl;

    return 0;
}

int lucky_tckt() {
    constexpr int lwr_six_dig_bndr = 100000;
    constexpr int uppr_six_dig_bndr = 999999;
    int num{};
    std::cout << "Type a number in range " << lwr_six_dig_bndr << "..."
        << uppr_six_dig_bndr << ": ";
    std::cin >> num;

    if ((num < lwr_six_dig_bndr) || (num > uppr_six_dig_bndr)) {
        std::cout << "Incorrect typed number" << std::endl;
        return 0;
    }
    int frst_prt{ num % 1000 }; // get last 3 digits
    int f_sum{};

    while (frst_prt > 0) {
        f_sum += frst_prt % 10;
        frst_prt /= 10;
    }

    num /= 1000; // cut source number to first 3 digits
    int scnd_prt{ num };
    int s_sum{};

    while (scnd_prt > 0) {
        s_sum += scnd_prt % 10;
        scnd_prt /= 10;
    }

    bool lucky{ (f_sum == s_sum) };
    std::cout << "Is the ticket lucky "
        << "- " << std::boolalpha << lucky << std::endl;

    return 0;
}

int reverse_num() {
    int32_t num{};
    std::cout << "Type a number: ";
    std::cin >> num;
    int res{};
    int coeff{ 100 };

    while (num) {
        res += (num % 10) * coeff;
        num /= 10;
        coeff /= 10;
    }

    std::cout << "Reverse number is " << res << std::endl;

    return 0;
}

int sum_odd_nmbrs() {
    constexpr int lwr_inpt{ 1 };
    constexpr int uppr_inpt{ 50 };
    constexpr int lwr_rng{ -60 };
    constexpr int uppr_rng{ 90 };
    int sum{};
    std::cout << "Type numbers: " << std::endl;

    for (int i = lwr_inpt; i <= uppr_inpt; i++) {
        int num{};
        std::cin >> num;
        if ((num >= lwr_rng) && (num <= uppr_rng)) {
            if (num & 1) { // bitwise check if number is odd
                sum += num;
            }
        }
        else {
            std::cout << num << " is out of range " << lwr_rng << ".." << uppr_rng
                << std::endl;
        }
    }

    std::cout << "Sum is " << sum << std::endl;

    return 0;
}

int best_divider() {
    int num{};
    std::cout
        << "Enter a number which for which you want to find a best devider: ";
    std::cin >> num;
    int max_best{};
    int count{ num };
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

    std::cout << "Enter a height of tree: ";
    std::cin >> num;

    if (!(num & 1)) { // bitwise check if number is even number
        num += 1;
    }
    int mdl = num / 2;
    int l_brdr{ mdl }; // initialize left and right borders middle num
    int r_brdr{ mdl };
    char astrsk{ '*' };
    char spc{ ' ' };
    for (int i = 0; i < num; i += 2) {
        for (int j = 0; j <= num; j++) {
            if ((j >= l_brdr) && (j <= r_brdr)) {
                std::cout << astrsk;
            }
            else {
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
    std::cout << "Enter a number: ";
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
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Enter a position of bit which you wanna check: ";
    std::cin >> ordr;
    if (ordr <= 0) {
        std::cout << ordr << " is incorrect a position number";
        return 0;
    }
    ordr -= 1;
    std::cout << (num & (1 << ordr) ? "Yes" : "No") << std::endl;
    return 0;
}

int build_num() {
    std::cout << "Enter amount of numbers: ";
    int amnt{};
    std::cin >> amnt;
    int sum{};
    std::cout << "Enter numbers which you want to check if they divided by 3: ";
    while (amnt > 0) {
        int tmp{};
        std::cin >> tmp;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        --amnt;
    }
    std::cout << ((sum % 3 == 0) ? "Yes" : "No") << std::endl;
    return 0;
}
int main() {
    sum_and_avrg();
    lucky_tckt();
    reverse_num();
    sum_odd_nmbrs();
    best_divider();
    build_tree();
    count_bits();
    is_bit_set();
    build_num();
    return 0;
}
