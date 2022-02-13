# compiler
CXX = g++
FLAGS = -Wall -Werror -std=c++17

# executable
EXE = geometry.out

# list of source files
SRC = main.cpp

# target for build executable
all: $(EXE)

$(EXE): $(SRC)
	$(CXX) $(FLAGS) $^ -o $@

# clean builded files
clean: 
	rm -rf $(EXE)

# program targets
.PHONY: all clean