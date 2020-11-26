#include <iostream>

int main() {
  int ticket_value{0};
  std::cout << "Please, enter you number" << std::endl;
  std::cin >> ticket_value;
  constexpr int min_ticket_value{0};
  constexpr int max_ticket_value{999999};
  if (ticket_value < min_ticket_value || ticket_value > max_ticket_value ||
      !(std::cin)) {
    std::cerr << "You entered wrong number. Please, try again" << '\n';
    return 0;
  }
  int second_half{0};
  for (int i = 1; i <= 3; ++i) {
    second_half += (ticket_value % 10);
    ticket_value /= 10;
  }
  int first_half{0};
  for (int i = 1; i <= 3; ++i) {
    first_half += (ticket_value % 10);
    ticket_value /= 10;
  }
  if (first_half == second_half) {
    std::cout << "Lucky ticket! Congratulations!" << '\n';
    return 0;
  }
  std::cout << "Unfortunately, it is not your day" << '\n';
  return 0;
}
