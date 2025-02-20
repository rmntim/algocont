#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {
inline auto PlaceCows(const std::vector<uint64_t>& stalls, size_t from, size_t cows) -> bool {
  size_t placed = 1;
  uint64_t prev = stalls.front();

  for (size_t i = 1; i < stalls.size(); ++i) {
    if (stalls.at(i) - prev >= from) {
      ++placed;
      prev = stalls.at(i);
    }
  }

  return placed >= cows;
}

auto FindMaxDistance(const std::vector<uint64_t>& stalls, size_t cows) -> size_t {
  size_t max_distance = 0;

  size_t first = 1;
  size_t last = stalls.back() - stalls.front() + 1;

  while (first <= last) {
    size_t middle = (last + first) / 2;

    if (PlaceCows(stalls, middle, cows)) {
      max_distance = middle;
      first = middle + 1;
    } else {
      last = middle - 1;
    }
  }

  return max_distance;
}
}  // namespace

auto main() -> int {
  size_t stall_cnt = 0;
  size_t cows_cnt = 0;

  std::cin >> stall_cnt;
  std::cin >> cows_cnt;

  std::vector<uint64_t> stalls(stall_cnt);
  for (size_t i = 0; i < stall_cnt; ++i) {
    std::cin >> stalls[i];
  }

  auto max_distance = FindMaxDistance(stalls, cows_cnt);
  std::cout << max_distance << "\n";
}
