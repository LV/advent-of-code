const std = @import("std");

pub const Solution = *const fn () callconv(.C) void;
extern "c" fn get_solution(year: u32, day: u32, part: u32) ?Solution;

pub fn runSolution(year: u32, day: u32, part: u32) !void {
    const solution_fn = get_solution(year, day, part) orelse return error.SolutionNotFound;
    solution_fn();
}
