#!/bin/bash

wdir=`pwd`
name=`basename $wdir`

script2_to_tex.py script.md > main.tex
lualatex -shell-escape main.tex
cp main.pdf $name.pdf
