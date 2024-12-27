#include "registry.h"

// Initialize the global function registry
std::unordered_map<std::string, SolutionFunction> function_registry;

void register_solution(const std::string& key, SolutionFunction func) {
    function_registry[key] = func;
}
