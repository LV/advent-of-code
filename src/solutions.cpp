#include "solutions.h"

extern "C" {
   // Function declarations
   void solve_2015_day1_part1();
   void solve_2015_day1_part2();
   void solve_2015_day2_part1();
   void solve_2015_day2_part2();
   void solve_2015_day3_part1();
   void solve_2015_day3_part2();
   void solve_2015_day5_part1();
   void solve_2015_day5_part2();

   solution_fn get_solution(unsigned int year, unsigned int day, unsigned int part) {
       switch (year) {
           case 2015:
               switch (day) {
                   case 1:
                       return part == 1 ? solve_2015_day1_part1 : solve_2015_day1_part2;
                   case 2:
                       return part == 1 ? solve_2015_day2_part1 : solve_2015_day2_part2;
                   case 3:
                       return part == 1 ? solve_2015_day3_part1 : solve_2015_day3_part2;
                   case 5:
                       return part == 1 ? solve_2015_day5_part1 : solve_2015_day5_part2;
               }
               break;
       }
       return nullptr;
   }
}
