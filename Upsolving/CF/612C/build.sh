#!/bin/bash

wdir=`pwd`
name=`basename $wdir`

lualatex -shell-escape main.tex
cp main.pdf $name.pdf
