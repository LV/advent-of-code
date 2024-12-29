#include <iostream>
#include <unordered_set>
#include <utility>
#include "registry.h"
#include "utils.h"

namespace y2015_d3 {

std::string coordinate_to_string(int x, int y) {
    return std::to_string(x) + "," + std::to_string(y);
}

void solve_part1() {
    std::string input = read_input(2015, 3);

    std::unordered_set<std::string> visited{};

    int x = 0;
    int y = 0;

    visited.insert(coordinate_to_string(0, 0));

    for (char ch : input) {
        if (ch == '^') y++;
        if (ch == 'v') y--;
        if (ch == '>') x++;
        if (ch == '<') x--;

        std::string coor = coordinate_to_string(x, y);
        if (auto iter = visited.find(coor); iter == visited.end())
            visited.insert(coor);
    }

    std::cout << visited.size() << "\n";
}

void solve_part2() {
    return;
}

} // END NAMESPACE

namespace {
    const bool registered_part1 = (register_solution("2015/day3_part1", y2015_d3::solve_part1), true);
    const bool registered_part2 = (register_solution("2015/day3_part2", y2015_d3::solve_part2), true);
}
