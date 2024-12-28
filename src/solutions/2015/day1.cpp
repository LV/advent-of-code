#include <iostream>
#include "registry.h"
#include "utils.h"

void solve_part1() {
    std::string input = read_input(2015, 1);

    int count = 0;
    for (char ch : input) {
        if (ch == '(') count++;
        if (ch == ')') count--;
    }

    std::cout << count << "\n";
}

void solve_part2() {
    std::string input = read_input(2015, 1);
}

namespace {
    const bool registered_part1 = (register_solution("2015/day1_part1", solve_part1), true);
    const bool registered_part2 = (register_solution("2015/day1_part2", solve_part2), true);
}
