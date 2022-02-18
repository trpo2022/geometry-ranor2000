# program name
PROG = geometry

# compiler
CXX = g++
FLAGS = -Wall -Werror -std=c++17

# executable
EXE = $(PROG).out

# list of source files
SRC = main.cpp

# targets for build executable
all: $(EXE)

# build section
$(EXE): $(SRC)
	$(CXX) $(FLAGS) $^ -o $@

# clean builded files
clean: 
	rm -rf $(EXE_LINUX)

run:
	./$(EXE)

# program targets
.PHONY: all clean run