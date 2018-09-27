BASENAME = 03_Revisao_C_Cpp_Tipos_de_dados_de_usuario

BASE_DIR = /home/edson/Aulas/2013_01/EDA
AULAS_DIR = build/aulas
CODES_DIR = build/codes
LISTAS_DIR = build/listas

# Console
CONSOLE_SOURCES = $(addsuffix .tr, $(BASENAME)) 
CONSOLE = $(addsuffix _Console.txt, $(BASENAME)) 

# Texto
TEXT_SOURCES = $(addsuffix .gr, $(BASENAME))
TEXT = $(addsuffix _Texto.pdf, $(BASENAME))

# Slides
SLIDES_FILE = main.tex
SLIDES_SOURCES = header.tex capa.tex tipos.tex depuracao.tex
SLIDES_DVI  = $(addsuffix .dvi, $(basename $(SLIDES_FILE)))
SLIDES_PS   = $(addsuffix .ps, $(basename $(SLIDES_FILE)))
SLIDES_PDF  = $(addsuffix .pdf, $(basename $(SLIDES_FILE)))
SLIDES  = $(addsuffix .pdf, $(BASENAME))

# Codigos
CODES_SOURCES = cadastro.c  main.c  primes.c  rotate.c  tabuada.c \
				complex.cpp  testcomplex.cpp complex.h  primes.h
CODES         = $(addsuffix _Codigos.zip, $(BASENAME))

# Lista
LISTA_FILE 		= lista.tex
LISTA_SOURCES 	= logo.tex
LISTA_DVI  		= $(addsuffix .dvi, $(basename $(LISTA_FILE)))
LISTA_PS		= $(addsuffix .ps, $(basename $(LISTA_FILE)))
LISTA_PDF		= $(addsuffix .pdf, $(basename $(LISTA_FILE)))
LISTA  			= $(addsuffix _Lista.pdf, $(BASENAME))


LISTA         = $(addsuffix _Lista.pdf, $(BASENAME))
INPUTS        = $(addsuffix _IO.tar.gz, $(BASENAME))

# Builds
BUILDS = $(SLIDES) $(CODES) $(LISTA)

.PHONY: clean dist-clean install

all: $(BUILDS)

$(TEXT): $(TEXT_SOURCES)
	@groff $< > temp.ps
	@ps2pdf temp.ps
	@mv temp.ps $@

$(CONSOLE): $(CONSOLE_SOURCES)
	@nroff $< > $@

$(CODES): $(CODES_SOURCES)
	@zip -r $@ $(CODES_SOURCES)

$(SLIDES): $(SLIDES_FILE) $(SLIDES_SOURCES)
	@latex $<
	@latex $<
	@dvips $(SLIDES_DVI)
	@ps2pdf $(SLIDES_PS)
	@cp $(SLIDES_PDF) $@

$(LISTA): $(LISTA_FILE) $(LISTA_SOURCES)
	@latex $<
	@latex $<
	@dvips $(LISTA_DVI)
	@ps2pdf $(LISTA_PS)
	@cp $(LISTA_PDF) $@

clean:
	@rm -f *~ *.dvi *.ps *.backup *.aux *.log *.nav *.out *.c.tex *.cpp.tex *.toc *.vrb *.dvi *.ps *.snm main.pdf prog *.o temp.* lista.pdf

dist-clean: clean
	@rm -f $(BUILDS)

install: $(BUILDS)
	@mkdir -p $(BASE_DIR)/$(AULAS_DIR) $(BASE_DIR)/$(CODES_DIR)
	@mkdir -p $(BASE_DIR)/$(LISTAS_DIR)
	@cp $(SLIDES) $(BASE_DIR)/$(AULAS_DIR)
#	@cp $(TEXT) $(BASE_DIR)/$(AULAS_DIR)
#	@cp $(CONSOLE) $(BASE_DIR)/$(AULAS_DIR)
	@cp $(LISTA) $(BASE_DIR)/$(LISTAS_DIR)
#	@cp $(INPUTS) $(BASE_DIR)/$(LISTAS_DIR)
	@cp $(CODES) $(BASE_DIR)/$(CODES_DIR)
