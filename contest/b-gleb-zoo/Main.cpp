#include <cstddef>
#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <utility>
#include <vector>

constexpr char AsciiCaseDiff = 32;

namespace {
auto CatchAnimals(const std::string& animals) -> std::optional<std::vector<size_t>> {
  std::vector<size_t> answer(animals.size() / 2);

  std::list<std::pair<size_t, char>> queue;

  size_t count = 0;
  for (size_t i = 0; i < animals.size(); i++) {
    if (std::isupper(animals[i]) != 0) {
      queue.emplace_back(i - count, animals.at(i));
    } else {
      queue.emplace_back(++count, animals.at(i));
    }
  }

  while (!queue.empty()) {
    const auto current = queue.front();
    const auto next = ++queue.begin();
    const auto last = queue.back();

    if (std::abs(current.second - last.second) == AsciiCaseDiff) {
      const auto trap = std::isupper(current.second) != 0 ? current : last;
      const auto animal = std::isupper(current.second) != 0 ? last : current;
      answer[trap.first] = animal.first;

      queue.pop_front();
      queue.pop_back();
    } else if (std::abs(current.second - next->second) == AsciiCaseDiff) {
      const auto trap = std::isupper(current.second) != 0 ? current : *next;
      const auto animal = std::isupper(current.second) != 0 ? *next : current;
      answer[trap.first] = animal.first;

      queue.pop_front();
      queue.pop_front();
    } else {
      break;
    }
  }

  if (!queue.empty()) {
    return std::nullopt;
  }

  return answer;
}
}  // namespace

auto main() -> int {
  std::string input;
  std::cin >> input;

  // No monadic operations ??? :(
  if (auto answer = CatchAnimals(input)) {
    std::cout << "Possible\n";
    for (const auto trap : *answer) {
      std::cout << trap << " ";
    }
  } else {
    std::cout << "Impossible";
  }

  std::cout << "\n";
}
