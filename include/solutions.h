#pragma once

extern "C" {
   typedef void (*solution_fn)();
   solution_fn get_solution(unsigned int year, unsigned int day, unsigned int part);
}
