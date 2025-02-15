#include <iostream>
#include <string>

namespace {
auto IsSquared(const std::string& str) -> bool {
  if (str.length() % 2 == 1) {
    return false;
  }

  size_t length = str.length();

  for (size_t i = length - 1; i >= length / 2; --i) {
    const auto& chr1 = str.at(i);
    const auto& chr2 = str.at(i - (length / 2));

    if (chr1 != chr2) {
      return false;
    }
  }

  return true;
}
}  // namespace

auto main() -> int {
  size_t str_cnt = 0;
  std::cin >> str_cnt;

  std::string input;
  std::getline(std::cin, input);

  for (size_t i = 0; i < str_cnt; ++i) {
    std::getline(std::cin, input);

    if (IsSquared(input)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
}
