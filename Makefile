.PHONY: build clean run

build:
	mkdir -p build
	cd build && cmake .. && cmake --build .

clean:
	rm -rf build

run:
	./zig-out/bin/AdventOfCode $(year) $(day) $(part)
