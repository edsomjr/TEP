TEXFILES = ${wildcard *.tex}
FIGS = $(addsuffix .png, $(basename $(TEXFILES)))

.SUFFIXES: .png .tex

%.png: %.tex
	@textogif -dpi 150 -png $<

all:
	@make figs

figs: $(FIGS)
	@echo $(FIGS)

clean:
	@rm -rf *.png *.log prog

