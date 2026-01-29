SRC = $(wildcard *.cpp)
OBJECTS = $(addsuffix .o, $(basename $(SRC)))
ARG ?= #Integer number as command line input parameter

OBJ = $(basename $(wildcard *.cxx))

all:
	$(MAKE) compile
	$(MAKE) hello
	$(MAKE) run

.cpp.o:
	$(CXX) -c $<

test:
	@echo $(SRC)
	@echo $(OBJECTS)

compile: $(OBJECTS)


hello: $(OBJECTS)
	$(CXX) $(OBJECTS) -o hello

run:
	@./hello $(ARG)

GARBAGE = $(wildcard *.o *~)
clean:
	rm -f $(GARBAGE)

cleanAll:
	rm -f hello
	$(MAKE) clean

test2:
	echo $(OBJ)