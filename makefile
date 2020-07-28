default: build

clean:
	rm -rf build

build:
	mkdir build && cd build && cmake .. && make