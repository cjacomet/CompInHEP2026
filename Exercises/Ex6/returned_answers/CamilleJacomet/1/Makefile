# ROOT flags
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS   := $(shell root-config --libs)

CXXFLAGS := -O -Wall -std=c++17 $(ROOTCFLAGS)

all: $(MAKE) tree; $(MAKE) hist

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

tree: randNTree.o
	$(CXX) -O randNTree.o $(ROOTLIBS) -o tree

hist: randHist.o
	$(CXX) -O randHist.o $(ROOTLIBS) -o hist

clean:
	rm -f *~ *.o

cleanAll: clean
	rm -f $(wildcard *.root tree hist)