#include <iostream>
#include "registry.h"
#include "utils.h"

namespace y2015_d1 {

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

    int char_count = 0;
    int count = 0;

    for (char ch : input) {
        char_count++;
        if (ch == '(') count++;
        if (ch == ')') count--;
        if (count == -1) break;
    }

    std::cout << char_count << "\n";
}

} // END NAMESPACE

namespace {
    const bool registered_part1 = (register_solution("2015/day1_part1", y2015_d1::solve_part1), true);
    const bool registered_part2 = (register_solution("2015/day1_part2", y2015_d1::solve_part2), true);
}
