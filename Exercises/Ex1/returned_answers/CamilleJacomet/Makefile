SRC = $(basename $(wildcard *.tex))
FMFFILE = diagrams

all:
	$(MAKE) -i tex
	$(MAKE) mf
	$(MAKE) tex
	$(MAKE) dvips
	$(MAKE) pdf

tex:
	latex $(SRC)

mf:
	mf "\mode=localfont; input $(FMFFILE).mf;"

dvips:
	dvips $(SRC) -o

pdf:
	ps2pdf $(SRC).ps

RM = $(sort $(wildcard *.dvi *.log *.aux $(FMFFILE)* *~))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean
	rm -rf *.ps

test:
	echo $(SRC)
