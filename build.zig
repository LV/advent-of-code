const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "AdventOfCode",
        .root_source_file = .{ .cwd_relative = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });

    exe.linkSystemLibrary("c++");
    exe.addLibraryPath(.{ .cwd_relative = "build" });
    exe.linkSystemLibrary("cpp_solutions");

    b.installArtifact(exe);
}
