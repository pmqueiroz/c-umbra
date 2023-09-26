const std = @import("std");
const io = std.io;

fn read_file(path: []const u8) !void {
    const file = try std.fs.cwd().openFile(path, .{});
    defer file.close();
    var buf_reader = io.bufferedReader(file.reader());
    const in_stream = buf_reader.reader();
    var buf: [1024]u8 = undefined;
    var lines: [][1024]u8 = undefined;

    // store each line in a array and return it
    while (try in_stream.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        lines[index] = line;
    }

    std.debug.print("{s}\n", .{lines});
}

pub fn main() !void {
    const file_path = "example/example.umb";

    try read_file(file_path);
    // std.debug.print("File contents:\n{s}\n", .{result});
}
