#include <iostream>
#include <vector>

namespace {
auto CountCycles(int n, const std::vector<int>& banks) -> int {
  auto visited = std::vector<int>(n + 1, 0);
  auto cnt = 0;

  for (auto i = 1; i <= n; ++i) {
    if (visited[i] != 0) {
      continue;
    }

    auto bank = i;
    while (visited[bank] == 0) {
      visited[bank] = i;
      bank = banks[bank];
    }

    if (visited[bank] == i) {
      ++cnt;
    }
  }
  return cnt;
}
}  // namespace

auto main() -> int {
  auto count = 0;
  std::cin >> count;

  auto banks = std::vector<int>(count + 1);
  for (auto i = 1; i <= count; ++i) {
    std::cin >> banks[i];
  }

  auto result = CountCycles(count, banks);
  std::cout << result << "\n";

  return 0;
}
