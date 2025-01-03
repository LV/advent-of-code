#include <iostream>
#include <unordered_set>
#include <utility>
#include "assertion.h"
#include "utils.h"

namespace y2015_d5 {
bool containsAtLeastThreeVowels(const std::string &s) {
    int vowelCount = 0;

    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowelCount++;
        if (vowelCount >= 3) return true;
    }

    return false;
}

bool containsAtLeastOneRepeatingLetter(const std::string &s) {
    for (size_t i=1; i<s.size(); i++) {
        if (s[i] == s[i-1]) return true;
    }
    return false;
}

bool containsBadStrings(const std::string &s) {
    std::vector<std::string> badStrings = { "ab", "cd", "pq", "xy" };

    for (size_t i=1; i<s.size(); i++) {
        if (std::find(badStrings.begin(), badStrings.end(), s.substr(i-1, 2)) == badStrings.end()) continue;
        return true;
    }

    return false;
}

bool isNiceString(const std::string &s) {
    return containsAtLeastThreeVowels(s) && containsAtLeastOneRepeatingLetter(s) && !containsBadStrings(s);
}

int solve_part1(std::vector<std::string> input) {
    int count = 0;

    for (std::string str : input) {
        if (isNiceString(str)) count++;
    }

    return count;
}

int solve_part2() {
    return 0; // STUB
}
} // END_NAMESPACE

extern "C" {
    void solve_2015_day5_part1() {
        std::cout << y2015_d5::solve_part1(read_input_lines(2015, 5)) << "\n";
    }

    void solve_2015_day5_part2() {
    }
}
