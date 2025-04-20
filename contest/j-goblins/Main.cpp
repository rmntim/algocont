#include <deque>
#include <iostream>
#include <vector>

namespace {
auto GoblinsAndQueues(int n, const std::vector<std::pair<char, int>>& ops) {
  auto size = std::size_t{0};
  auto first = std::deque<int>{};
  auto last = std::deque<int>{};
  auto result = std::vector<int>{};
  result.reserve(n);

  auto move_between = [&]() {
    if (!last.empty()) {
      first.push_back(last.front());
      last.pop_front();
    }
  };

  auto equalize = [&]() {
    if (size % 2 == 0) {
      move_between();
    }
  };

  for (auto i = 0; i < n; ++i) {
    auto [op, id] = ops[i];
    if (op == '+') {
      last.push_back(id);
      equalize();
      ++size;
    } else if (op == '*') {
      if (size % 2 == 0) {
        first.push_back(id);
      } else {
        last.push_front(id);
      }
      ++size;
    } else {  // op == '-'
      auto ans = first.front();
      first.pop_front();
      equalize();
      --size;
      result.push_back(ans);
    }
  }
  return result;
}
}  // namespace

int main() {
  auto req_cnt = 0;
  std::cin >> req_cnt;

  auto ops = std::vector<std::pair<char, int>>{};
  ops.reserve(req_cnt);

  for (auto i = 0; i < req_cnt; ++i) {
    char operation{};
    std::cin >> operation;
    if (operation == '+' || operation == '*') {
      auto index = 0;
      std::cin >> index;
      ops.emplace_back(operation, index);
    } else {
      ops.emplace_back(operation, 0);
    }
  }

  auto answers = GoblinsAndQueues(req_cnt, ops);
  for (auto answer : answers) {
    std::cout << answer << "\n";
  }
  return 0;
}
