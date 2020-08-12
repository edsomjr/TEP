#!/bin/bash

wdir=`pwd`
name=`basename $wdir`

pdflatex -shell-escape main.tex
cp main.pdf $name.pdf
