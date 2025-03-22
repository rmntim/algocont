#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace {
auto CompareForMaxNumber(const std::string& first, const std::string& second) -> bool {
  return first + second > second + first;
}

auto FindMaxNumber(std::vector<std::string>& pieces) -> std::string {
  std::ranges::sort(pieces, CompareForMaxNumber);

  return std::reduce(
      pieces.begin(),
      pieces.end(),
      std::string{},
      [](const std::string& acc, const std::string& piece) { return acc + piece; }
  );
}
}  // namespace

auto main() -> int {
  std::vector<std::string> pieces;
  std::string input;

  while (std::cin >> input) {
    pieces.emplace_back(input);
  }

  auto max_number = FindMaxNumber(pieces);

  std::cout << max_number << '\n';

  return 0;
}
