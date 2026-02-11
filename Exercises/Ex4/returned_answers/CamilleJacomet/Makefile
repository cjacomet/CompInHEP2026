RT_OBJ = src/RecTrack.o
SP_OBJ = src/SimPart.o

OPT = -O -Wall -fPIC -std=c++17

INC = -Iinclude

LIBS = -L. -lSimPart -lRecTrack

all:
	$(MAKE) libRecTrack.so
	$(MAKE) libSimPart.so
	$(CXX) test.cpp $(INC) $(LIBS) -std=c++17 -o test

libRecTrack.so: $(RT_OBJ)
	$(CXX) -shared -o $@ $^

libSimPart.so: $(SP_OBJ) libRecTrack.so
	$(CXX) -shared -o $@ $(SP_OBJ) -L. -lRecTrack

.cc.o:
	$(CXX) -c $(OPT) $(INC) $< -o $@


clean:
	rm src/*.o

cleanAll:
	$(MAKE) clean
	rm test *.so