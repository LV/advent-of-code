#pragma once
#include <string>
#include <functional>
#include <unordered_map>
#include <iostream>

using SolutionFunction = std::function<void()>;
extern std::unordered_map<std::string, SolutionFunction> function_registry;

void register_solution(const std::string& key, SolutionFunction func);

inline std::string generate_key(int year, int day, int part) {
    return std::to_string(year) + "/day" + std::to_string(day) + "_part" + std::to_string(part);
}
