#include <iostream>
#include <unordered_set>
#include <utility>
#include "assertion.h"
#include "utils.h"

namespace y2015_d3 {
std::string coordinate_to_string(int x, int y) {
    return std::to_string(x) + "," + std::to_string(y);
}

int solve_part1(std::string input) {
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

    return visited.size();
}

int solve_part2(std::string input) {
    // FIXME: Test cases are failing

    std::unordered_set<std::string> visited{};

    int x_robo = 0;
    int y_robo = 0;
    int x_santa = 0;
    int y_santa = 0;

    bool isRoboMoving = true; // when false, Santa moves

    for (char ch : input) {
        if (isRoboMoving) {
            if (ch == '^') y_robo++;
            if (ch == 'v') y_robo--;
            if (ch == '>') x_robo++;
            if (ch == '<') x_robo--;
            std::string coor = coordinate_to_string(x_robo, y_robo);
            if (auto iter = visited.find(coor); iter == visited.end())
                visited.insert(coor);
            isRoboMoving = false;
        } else {
            if (ch == '^') y_santa++;
            if (ch == 'v') y_santa--;
            if (ch == '>') x_santa++;
            if (ch == '<') x_santa--;
            std::string coor = coordinate_to_string(x_santa, y_santa);
            if (auto iter = visited.find(coor); iter == visited.end())
                visited.insert(coor);
            isRoboMoving = true;
        }
    }

    return visited.size();
}
} // END_NAMESPACE

extern "C" {
    void solve_2015_day3_part1() {
        ASSERT(y2015_d3::solve_part1(">") == 2, "Test case 1 failed");
        ASSERT(y2015_d3::solve_part1("^>v<") == 4, "Test case 2 failed");
        ASSERT(y2015_d3::solve_part1("^v^v^v^v^v") == 2, "Test case 3 failed");
        std::cout << y2015_d3::solve_part1(read_input(2015, 3)) << "\n";
    }

    void solve_2015_day3_part2() {
        ASSERT(y2015_d3::solve_part1("^v") == 3, "Test case 1 failed");
        ASSERT(y2015_d3::solve_part1("^>v<") == 3, "Test case 2 failed");
        ASSERT(y2015_d3::solve_part1("^v^v^v^v^v") == 11, "Test case 3 failed");
        std::cout << y2015_d3::solve_part2(read_input(2015, 3)) << "\n";
    }
}
