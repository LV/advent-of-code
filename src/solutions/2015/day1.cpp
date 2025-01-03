#include <iostream>
#include "utils.h"
#include "assertion.h"

namespace y2015_d1 {
int solve_part1(std::string input) {
    int count = 0;
    for (char ch : input) {
        if (ch == '(') count++;
        if (ch == ')') count--;
    }

    return count;
}

int solve_part2(std::string input) {
    int char_count = 0;
    int count = 0;

    for (char ch : input) {
        char_count++;
        if (ch == '(') count++;
        if (ch == ')') count--;
        if (count == -1) break;
    }

    return char_count;
}
} // END_NAMESPACE

extern "C" {
    void solve_2015_day1_part1() {
        ASSERT(y2015_d1::solve_part1("(())") == 0, "Test case 1 failed");
        ASSERT(y2015_d1::solve_part1("()()") == 0, "Test case 2 failed");
        ASSERT(y2015_d1::solve_part1("(((") == 3, "Test case 3 failed");
        ASSERT(y2015_d1::solve_part1("(()(()(") == 3, "Test case 4 failed");
        ASSERT(y2015_d1::solve_part1("))(((((") == 3, "Test case 5 failed");
        ASSERT(y2015_d1::solve_part1("())") == -1, "Test case 6 failed");
        ASSERT(y2015_d1::solve_part1("))(") == -1, "Test case 7 failed");
        ASSERT(y2015_d1::solve_part1(")))") == -3, "Test case 8 failed");
        ASSERT(y2015_d1::solve_part1(")())())") == -3, "Test case 9 failed");
        std::cout << y2015_d1::solve_part1(read_input(2015, 1)) << "\n";
    }

    void solve_2015_day1_part2() {
        ASSERT(y2015_d1::solve_part2(")") == 1, "Test case 1 failed");
        ASSERT(y2015_d1::solve_part2("()())") == 5, "Test case 2 failed");
        std::cout << y2015_d1::solve_part2(read_input(2015, 1)) << "\n";
    }
}
