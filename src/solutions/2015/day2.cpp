#include <algorithm>
#include <iostream>
#include "registry.h"
#include "utils.h"

namespace y2015_d2 {

class Rectangle {
private:
    int length;
    int width;
    int height;

public:
    Rectangle(std::string line) {
        size_t pos = line.find('x');
        length = std::stoi(line.substr(0, pos));
        line = line.substr(pos+1, line.size());

        pos = line.find('x');
        width = std::stoi(line.substr(0, pos));
        line = line.substr(pos+1, line.size());

        height = std::stoi(line.substr(0, line.size()));
    }

    int surface_area() {
        return (2*length*width) + (2*width*height) + (2*height*length);
    }

    int smallest_side_area() {
        return std::min(width*length, std::min(length*height, width*height));
    }
};

void solve_part1() {
    std::vector<std::string> input = read_input_lines(2015, 2);

    int total = 0;
    for (std::string line : input) {
        Rectangle r = Rectangle(line);
        total += r.surface_area() + r.smallest_side_area();
    }

    std::cout << total << "\n";
}

void solve_part2() {
    std::string input = read_input(2015, 2);
}

} // END NAMESPACE

namespace {
    const bool registered_part1 = (register_solution("2015/day2_part1", y2015_d2::solve_part1), true);
    const bool registered_part2 = (register_solution("2015/day2_part2", y2015_d2::solve_part2), true);
}
