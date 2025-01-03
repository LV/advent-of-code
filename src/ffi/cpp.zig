const std = @import("std");

pub const Solution = fn () callconv(.C) void;
extern "c" fn get_solution(year: u32, day: u32, part: u32) ?Solution;

pub fn runSolution(year: u32, day: u32, part: u32) !void {
    if (get_solution(year, day, part)) |solution| {
        solution();
    } else {
        return error.SolutionNotFound;
    }
}
