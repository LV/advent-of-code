const cpp = @import("ffi/cpp.zig");
const std = @import("std");

const earliest_aoc_year: u16 = 2015;
const latest_aoc_year: u16 = 2024;
const min_day: u8 = 1;
const max_day: u8 = 25;

fn runSolution(year: u16, day: u8, part: u8) !void {
    try cpp.runSolution(year, day, part);
}

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    var args = try std.process.argsWithAllocator(allocator);
    defer args.deinit();

    // Skip program name
    _ = args.next();

    if (args.next()) |first_arg| {
        if (std.mem.eql(u8, first_arg, "--help") or std.mem.eql(u8, first_arg, "-h")) {
            std.debug.print("Usage: ./aoc-zig <year> <day> <part>\n\n", .{});
            std.debug.print("Example: ./aoc-zig 2020 4 2\n", .{});
            return;
        }

        const year = try std.fmt.parseInt(u16, first_arg, 10);
        const day = try std.fmt.parseInt(u8, args.next() orelse return error.MissingDay, 10);
        const part = try std.fmt.parseInt(u8, args.next() orelse return error.MissingPart, 10);

        if (year < earliest_aoc_year or year > latest_aoc_year) {
            std.debug.print("Year must be between {} and {}\n", .{ earliest_aoc_year, latest_aoc_year });
            return error.InvalidYear;
        }

        if (day < min_day or day > max_day) {
            std.debug.print("Day must be between {} and {}\n", .{ min_day, max_day });
            return error.InvalidDay;
        }

        if (part != 1 and part != 2) {
            std.debug.print("Part must be 1 or 2\n", .{});
            return error.InvalidPart;
        }

        try runSolution(year, day, part);
        return;
    }

    std.debug.print("Run with `--help` for more information\n", .{});
    std.debug.print("Usage: ./aoc-zig <year> <day> <part>\n", .{});
}
