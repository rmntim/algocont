#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

namespace {
auto LongestRange(const std::vector<uint64_t>& flowers) -> std::pair<size_t, size_t> {
  if (flowers.size() < 3) {
    return std::make_pair(1, flowers.size());
  }

  std::pair<size_t, size_t> range(0, 1);
  std::pair<size_t, size_t> max = range;

  for (size_t i = 2; i < flowers.size(); ++i) {
    if (flowers[i] == flowers[i - 1] && flowers[i - 1] == flowers[i - 2]) {
      range = std::make_pair(i - 1, i);
      continue;
    }

    range.second++;

    if (range.second - range.first + 1 > max.second - max.first + 1) {
      max = range;
    }
  }

  max.first++;
  max.second++;

  return max;
}
}  // namespace

auto main() -> int {
  size_t n_cnt = 0;

  std::cin >> n_cnt;

  std::vector<uint64_t> flowers;
  flowers.reserve(n_cnt);

  uint64_t current = 0;
  for (size_t i = 0; i < n_cnt; ++i) {
    std::cin >> current;
    flowers.push_back(current);
  }

  auto answer = LongestRange(flowers);
  std::cout << answer.first << " " << answer.second << "\n";
}
