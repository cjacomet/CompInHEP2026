PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8317.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

SRC = $(wildcard *.cc)
OBJS = $(addsuffix .o,$(basename $(SRC)))

OPT = -g -Wall
INC = -I$(PYTHIA8_DIR)/include
LIBS = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl -Wl,-rpath,./pythia8317/lib

.cc.o:
	$(CXX) $(OPT) $(INC) -c -o $@ $<

$(PYTHIA8_DIR):
	wget $(PYTHIA8_URL)
	tar xfvz $(PYTHIA8_TGZ)
	cd $(PYTHIA8_DIR) && ./configure && make -j 8

all:
	$(MAKE) $(PYTHIA8_DIR)

compile: $(OBJS)

muons: $(OBJS) $(PYTHIA8_DIR)
	$(MAKE) compile
	$(CXX) $(OPT) $(INC) $(OBJS) $(LIBS) -o muons

test:
	echo $(INC) $(LIBS)

files = $(wildcard *~ *.out *.C)
files+= $(OBJS)
clean:
	rm -rf $(files)

cleanAll:
	$(MAKE) clean
	rm -rf pythia* muons
