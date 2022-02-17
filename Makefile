# compiler
CXX = g++
CXX_WIN64 = x86_64-w64-mingw32-g++

FLAGS = -Wall -Werror -std=c++17
FLAGS_W64 = --static

# executable
PROG = geometry
EXE = $(PROG).out
EXE_WIN64 = $(PROG).exe

# list of source files
SRC = main.cpp

# targets for build executable
# building for linux by default
all: linux

linux: $(EXE)

win64: $(EXE_WIN64)

# build section
$(EXE): $(SRC)
	$(CXX) $(FLAGS) $^ -o $@

$(EXE_WIN64): $(SRC)
	$(CXX_WIN64) $(FLAGS) $(FLAGS_W64) $^ -o $@

# clean builded files
clean: 
	rm -rf $(EXE_LINUX) $(EXE_WIN64)

# program targets
.PHONY: all clean win64 linux