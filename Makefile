all:
	mkdir -p build
	clang main.c -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl -o build/pln

run:
	./build/pln

clean:
	rm -rf build

.PHONY: run clean
