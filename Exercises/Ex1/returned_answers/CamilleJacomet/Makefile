SRC = $(basename $(wildcard *.tex))
FMFFILE = diagrams
BIBFILE = references

all:
	$(MAKE) -i tex
	$(MAKE) bib
	$(MAKE) mf
	$(MAKE) tex
	# Second latex pass to solve cross-references
	$(MAKE) tex
	$(MAKE) dvips
	$(MAKE) pdf

tex:
	latex $(SRC)

bib:
	bibtex $(SRC)

mf:
	mf "\mode=localfont; input $(FMFFILE).mf;"

dvips:
	dvips $(SRC) -o

pdf:
	ps2pdf $(SRC).ps

RM = $(sort $(wildcard *.dvi *.log *.aux *.bbl *.blg $(FMFFILE)* *~))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean
	rm -rf *.ps
