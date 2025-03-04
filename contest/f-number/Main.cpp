#include <iostream>
#include <string>
#include <vector>

namespace {
using Iterator = std::vector<std::string>::iterator;

auto Permutations(
    const std::vector<std::string>& numbers, Iterator start, Iterator end, std::string& max_number
) -> void {
  if (start == end) {
    std::string temp;
    for (const auto& number : numbers) {
      temp += number;
    }

    if (temp > max_number) {
      max_number = temp;
    }
  } else {
    for (auto i = start; i != end; i++) {
      std::iter_swap(start, i);
      Permutations(numbers, start + 1, end, max_number);
      std::iter_swap(start, i);
    }
  }
}

auto Permutations(std::vector<std::string>& numbers) -> std::string {
  std::string max_number = "0";
  Permutations(numbers, numbers.begin(), numbers.end(), max_number);
  return max_number;
}
}  // namespace

auto main() -> int {
  std::vector<std::string> numbers;

  for (std::string input; std::getline(std::cin, input);) {
    numbers.emplace_back(input);
  }

  auto max_number = Permutations(numbers);

  std::cout << max_number << '\n';
}
