#include <iostream>
#include <limits>

int main() {
  int ticket_value{0};
  std::cin >> ticket_value;
  if (ticket_value < 0 || ticket_value > 999999 || !(std::cin)) {
    std::cout << "You entered wrong number. Please, try again" << '\n';
    return 0;
  }
  int second_half{0};
  for (int i = 0; i < 3; ++i) {
    second_half += (ticket_value % 10);
    ticket_value /= 10;
  }
  int first_half{0};
  for (int i = 0; i < 3; ++i) {
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