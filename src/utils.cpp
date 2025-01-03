#include "utils.h"
#include <fstream>
#include <iostream>

// Read the entire input file as a single string
std::string read_input(int year, int day) {
    // Construct the file path dynamically
    std::string file_path = "inputs/" + std::to_string(year) + "/day" + std::to_string(day) + ".txt";

    // Open the file
    std::ifstream input_file(file_path);
    if (!input_file) {
        std::cerr << "Error: Could not open input file: " << file_path << std::endl;
        return "";
    }

    // Read the entire file into a string
    return std::string((std::istreambuf_iterator<char>(input_file)),
                       std::istreambuf_iterator<char>());
}

// Read the input file line by line into a vector of strings
std::vector<std::string> read_input_lines(int year, int day) {
    // Construct the file path dynamically
    std::string file_path = "inputs/" + std::to_string(year) + "/day" + std::to_string(day) + ".txt";

    // Open the file
    std::ifstream input_file(file_path);
    if (!input_file) {
        std::cerr << "Error: Could not open input file: " << file_path << std::endl;
        return {};
    }

    // Read the file line by line
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }

    return lines;
}
