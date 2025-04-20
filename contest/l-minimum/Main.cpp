#include <deque>
#include <iostream>
#include <vector>

namespace {
auto MinOnSegment(int seq_len, int window_len, const std::vector<int>& seq) {
  auto deq = std::deque<int>{};
  auto result = std::vector<int>{};
  result.reserve(seq_len - window_len + 1);

  for (auto i = 0; i < seq_len; ++i) {
    while (!deq.empty() && seq[deq.back()] > seq[i]) {
      deq.pop_back();
    }
    deq.push_back(i);

    if (deq.front() <= i - window_len) {
      deq.pop_front();
    }

    if (i >= window_len - 1) {
      result.push_back(seq[deq.front()]);
    }
  }
  return result;
}
}  // namespace

int main() {
  int seq_len{};
  int window_len{};
  std::cin >> seq_len >> window_len;

  auto seq = std::vector<int>(seq_len);
  for (auto& seq_elem : seq) {
    std::cin >> seq_elem;
  }

  auto answer = MinOnSegment(seq_len, window_len, seq);
  for (auto ans : answer) {
    std::cout << ans << " ";
  }
  std::cout << "\n";

  return 0;
}
