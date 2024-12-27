#include <iostream>
#include "registry.h"

void solve_part1() {
    std::cout << "Hello son\n";
}

void solve_part2() {
    std::cout << "Hello sonny\n";
}

namespace {
    const bool registered_part1 = (register_solution("2015/day1_part1", solve_part1), true);
    const bool registered_part2 = (register_solution("2015/day1_part2", solve_part2), true);
}
