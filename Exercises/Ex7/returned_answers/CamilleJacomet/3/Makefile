PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8317.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

GARBAGE = $(wildcard *~ *.o *.a *.so higgs_sim pythia8* *.job *.txt)

OPT = -O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC
INC = -I$(PYTHIA8_DIR)/include
LIBS = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl

OBJ = $(addsuffix .o,$(basename $(wildcard *.cpp)))

all:
	$(MAKE) p8get
	$(MAKE) compile
	$(MAKE) higgs_sim
	$(MAKE) job

p8get:
	wget $(PYTHIA8_URL) && tar xfvz $(PYTHIA8_TGZ) && cd $(PYTHIA8_DIR) && ./configure && make

.cpp.o:
	$(CXX) $(OPT) $(INC) -c $^ -o $@



compile: $(OBJ)

higgs_sim:	$(OBJ)
	$(CXX) $(OPT) $(INC) $@.o $(LIBS) -o higgs_sim

job:
	echo '#!'`which bash` > test.job 
	echo 'export DYLD_LIBRARY_PATH=$(PWD)/$(PYTHIA8_DIR)/lib' >> test.job
	echo 'export PYTHIA8DATA=$(PWD)/pythia8317/share/Pythia8/xmldoc' >> test.job
	echo './higgs_sim' >> test.job
	chmod +x test.job

clean:
	rm -rf $(GARBAGE)