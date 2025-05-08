#include <cstdint>
#include <iostream>
#include <vector>

namespace {
auto IsBipartite(int n, const std::vector<std::vector<int>>& adj) -> bool {
  std::vector<int> color(n + 1, -1);

  for (auto start = 1; start <= n; ++start) {
    if (color[start] != -1) {
      continue;
    }

    std::queue<int> queue;
    color[start] = 0;
    queue.push(start);

    while (!queue.empty()) {
      auto next = queue.front();
      queue.pop();

      for (auto elem : adj[next]) {
        if (color[elem] == -1) {
          color[elem] = static_cast<int>(static_cast<uint64_t>(color[next]) ^ 1U);
          queue.push(elem);
        } else if (color[elem] == color[next]) {
          return false;
        }
      }
    }
  }
  return true;
}
}  // namespace

auto main() -> int {
  auto count = 0;
  auto pair_count = 0;
  std::cin >> count >> pair_count;

  std::vector<std::vector<int>> adj(count + 1);
  for (auto i = 0; i < pair_count; ++i) {
    auto first = 0;
    auto second = 0;
    std::cin >> first >> second;

    adj[first].push_back(second);
    adj[second].push_back(first);
  }

  std::cout << (IsBipartite(count, adj) ? "YES" : "NO") << "\n";
  return 0;
}
