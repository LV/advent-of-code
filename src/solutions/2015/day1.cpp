#include <iostream>
#include "utils.h"

extern "C" {
    void solve_2015_day1_part1() {
        std::string input = read_input(2015, 1);

        int count = 0;
        for (char ch : input) {
            if (ch == '(') count++;
            if (ch == ')') count--;
        }

        std::cout << count << "\n";
    }

    void solve_2015_day1_part2() {
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
}
