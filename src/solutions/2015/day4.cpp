#include <iostream>
#include <unordered_set>
#include <utility>
#include "registry.h"
#include "utils.h"

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>  // for scoped_interpreter


namespace py = pybind11;

namespace y2015_d4 {

std::string SECRET_KEY = "ckczppom";


std::string get_md5_hash(const std::string &input) {
    py::module hashlib = py::module::import("hashlib");

    auto hash_obj = hashlib.attr("md5")();
    hash_obj.attr("update")(py::bytes(input));
    return py::str(hash_obj.attr("hexdigest")());
}

void solve_part1() {
    py::scoped_interpreter guard{};  // Initialize Python interpreter first

    // std::string secret_key = read_input(2015, 4); // doesn't work for some reason!
    
    int number = 0;
    std::string md5hash;

    while (true) {
        md5hash = get_md5_hash(SECRET_KEY + std::to_string(number));
        if (md5hash.substr(0, 5) == "00000") break;
        number++;
    }

    std::cout << number << "\n";
}

void solve_part2() {
    py::scoped_interpreter guard{};  // Initialize Python interpreter first
    
    int number = 0;
    std::string md5hash;

    while (true) {
        md5hash = get_md5_hash(SECRET_KEY + std::to_string(number));
        if (md5hash.substr(0, 6) == "000000") break;
        number++;
    }

    std::cout << number << "\n";
}

} // END NAMESPACE

namespace {
    const bool registered_part1 = (register_solution("2015/day4_part1", y2015_d4::solve_part1), true);
    const bool registered_part2 = (register_solution("2015/day4_part2", y2015_d4::solve_part2), true);
}
