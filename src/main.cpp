#include <charconv>
#include <filesystem>
#include <format>
#include <iostream>
#include <span>
#include "registry.h"

const int EARLIEST_AOC_YEAR = 2015;
const int LATEST_AOC_YEAR = 2024;
const int MIN_DAY = 1;
const int MAX_DAY = 25;

void run_solution(int year, int day, int part) {
    std::string key = generate_key(year, day, part);

    auto it = function_registry.find(key);
    if (it != function_registry.end()) {
        it->second(); // Call the solution function
    } else {
        std::cout << year << " Day " << day << " Part " << part << " has not been solved yet!\n";
    }
}

int main(int argc, char* argv[]) {
    std::cout << "Luis Victoria's Advent of Code Solutions\n\n";

    if (argc < 2) {
        std::cout << "Run with `--help` for more information\n";
        std::cout << "Usage: ./AdventOfCode <year> <day> <part>\n";
        return 1;
    }

    if (argc == 2) {
        std::string_view command{argv[1]};
        if (command == "--help" || command == "-h") {
            std::cout << "Usage: ./AdventOfCode <year> <day> <part>\n";
            std::cout << "\n";
            std::cout << "Example: ./AdventOfCode 2020 4 2\n";

            return 0;
        }

    }

    if (argc == 4) {
        std::string_view year_str{argv[1]};
        std::string_view day_str{argv[2]};
        std::string_view part_str{argv[3]};
        int year;
        int day;
        int part;

        auto year_res = std::from_chars(year_str.data(), year_str.data() + year_str.size(), year);
        auto day_res = std::from_chars(day_str.data(), day_str.data() + day_str.size(), day);
        auto part_res = std::from_chars(part_str.data(), part_str.data() + part_str.size(), part);

        if (year_res.ec != std::errc{}) {
            std::cout << "Year is an invalid number format\n";
            return 1;
        }

        if (day_res.ec != std::errc{}) {
            std::cout << "Day is an invalid number format\n";
            return 1;
        }

        if (part_res.ec != std::errc{}) {
            std::cout << "Part is an invalid number format\n";
            return 1;
        }

        if (year < EARLIEST_AOC_YEAR || year > LATEST_AOC_YEAR) {
            std::cout << "Year must be between " << EARLIEST_AOC_YEAR << " to " << LATEST_AOC_YEAR << "\n";
            std::cout << "You entered: " << year << "\n";
            return 1;
        }

        if (day < MIN_DAY || day > MAX_DAY) {
            std::cout << "Day must be between " << MIN_DAY << " and " << MAX_DAY << "\n";
            std::cout << "You entered: " << day << "\n";
            return 1;
        }

        if (part != 1 && part != 2) {
            std::cout << "Part must be 1 or 2\n";
            std::cout << "You entered: " << part << "\n";
            return 1;
        }

        run_solution(year, day, part);
        return 0;
    }

    std::cout << "Invalid number of arguments! Run with `--help`\n";
    std::cout << "Usage: ./AdventOfCode <year> <day> <part>\n";
    return 1;
}
