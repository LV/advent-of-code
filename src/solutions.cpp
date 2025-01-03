// include/solutions.h
#pragma once

extern "C" {
   typedef void (*solution_fn)();
   solution_fn get_solution(unsigned int year, unsigned int day, unsigned int part);
}

// src/solutions.cpp
#include "solutions.h"

extern "C" {
   // Function declarations
   void solve_2015_day1_part1();
   void solve_2015_day1_part2();
   void solve_2015_day2_part1();
   void solve_2015_day2_part2();

   solution_fn get_solution(unsigned int year, unsigned int day, unsigned int part) {
       switch (year) {
           case 2015:
               switch (day) {
                   case 1:
                       return part == 1 ? solve_2015_day1_part1 : solve_2015_day1_part2;
                   case 2:
                       return part == 1 ? solve_2015_day2_part1 : solve_2015_day2_part2;
               }
               break;
       }
       return nullptr;
   }
}
