SRC = $(wildcard *.cpp)
OBJECTS = $(addsuffix .o, $(basename $(SRC)))
ARG ?= #Integer number as command line input parameter for hello

all:
	$(MAKE) compile
	$(MAKE) hello
# $(MAKE) run

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
OUTPUT = $(wildcard *.txt)
clean:
	rm -f $(GARBAGE)

cleanAll:
	rm -f hello
	rm -f $(OUTPUT)
	$(MAKE) clean