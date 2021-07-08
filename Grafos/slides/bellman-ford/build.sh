#!/bin/bash

wdir=`pwd`
name=`basename $wdir`

script_to_tex.py script2.md > main.tex
lualatex -shell-escape main.tex
cp main.pdf $name.pdf
