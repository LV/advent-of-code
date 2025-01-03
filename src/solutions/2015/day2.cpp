#include <algorithm>
#include <iostream>
#include "assertion.h"
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

    int area() {
        return length*width*height;
    }

    int least_ribbon() {
        return std::min((length*2)+(width*2), std::min((width*2)+(height*2),(length*2)+(height*2)));
    }
};

int solve_part1(std::vector<std::string> input) {
    int total = 0;
    for (std::string line : input) {
        Rectangle r = Rectangle(line);
        total += r.surface_area() + r.smallest_side_area();
    }

    return total;
}

int solve_part2(std::vector<std::string> input) {
    int total = 0;
    for (std::string line : input) {
        Rectangle r = Rectangle(line);
        total += r.least_ribbon() + r.area();
    }

    return total;
}

} // END_NAMESPACE

extern "C" {
    void solve_2015_day2_part1() {
        ASSERT(y2015_d2::solve_part1({"2x3x4"})== 58, "Test case 1 failed");
        ASSERT(y2015_d2::solve_part1({"1x1x10"}) == 43, "Test case 2 failed");
        std::cout << y2015_d2::solve_part1(read_input_lines(2015,2)) << "\n";
    }

    void solve_2015_day2_part2() {
        ASSERT(y2015_d2::solve_part2({"2x3x4"})== 34, "Test case 1 failed");
        ASSERT(y2015_d2::solve_part2({"1x1x10"}) == 14, "Test case 2 failed");
        std::cout << y2015_d2::solve_part2(read_input_lines(2015, 2)) << "\n";
    }
}

