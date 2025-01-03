#include <iostream>
#include <unordered_set>
#include <utility>
#include "utils.h"

std::string coordinate_to_string(int x, int y) {
    return std::to_string(x) + "," + std::to_string(y);
}

extern "C" {
    void solve_2015_day3_part1() {
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

    void solve_2015_day3_part2() {
        std::string input = read_input(2015, 3);

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

        std::cout << visited.size() << "\n";
    }
}
