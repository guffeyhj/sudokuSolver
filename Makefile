SRC := $(wildcard ./src/*.cpp)
OBJ := $(patsubst ./src/%.cpp, ./build/%.o, $(SRC))

./bin/sudokuSolver: $(OBJ)
	g++ $^ -o $@

./build/%.o: ./src/%.cpp
	g++ -c $< -o $@

.PHONY: test
test:
	echo $(SRC)
	echo $(OBJ)

.PHONY: clean
clean:
	rm -rf ./build/*
	rm -rf ./bin/sudokuSolver
	rm -rf ./bin/test.ssolv
	rm -rf ./bin/poss.ssolv