#include <iostream>
#include <unordered_set>
#include <utility>
#include "utils.h"

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

extern "C" {
    void solve_part1() {
        std::vector<std::string> input = read_input_lines(2015, 5);

        int count = 0;

        for (std::string str : input) {
            if (isNiceString(str)) count++;
        }

        std::cout << count << "\n";
    }

    void solve_part2() {
    }
}
