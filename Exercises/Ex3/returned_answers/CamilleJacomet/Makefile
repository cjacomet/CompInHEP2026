# Flags
CXXFLAGS := -std=c++17 -Wall -O2 -fPIC

# Names
LIB_NAME := libmet.so
TEST_EXE := test

# Sources
LIB_SRC  := Met.cpp
LIB_OBJ  := Met.o
TEST_SRC := test.cpp
TEST_OBJ := test.o

all: 
	$(MAKE) $(LIB_NAME) 
	$(MAKE) $(TEST_EXE)

# Shared library
$(LIB_NAME): $(LIB_OBJ)
	$(CXX) -shared -o $@ $^

$(LIB_OBJ): Met.cpp Met.h
	$(CXX) $(CXXFLAGS) -c Met.cpp

# Executable for test
$(TEST_EXE): $(TEST_OBJ) $(LIB_NAME)
	$(CXX) -o $@ $(TEST_OBJ) -L. -lmet

$(TEST_OBJ): test.cpp Met.h
	$(CXX) $(CXXFLAGS) -c test.cpp

# Run test with correct runtime library path
run:
	LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH ./test

# Clean up
GARBAGE = $(wildcard *.o *~)
clean:
	rm -f $(GARBAGE)
	rm -f $(LIB_NAME)
	rm -f $(TEST_EXE)

.PHONY: all clean run
