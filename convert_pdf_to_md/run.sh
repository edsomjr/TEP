#!/bin/bash
const0=1
const1=2
a=$1 # ex: SSP2.pdf
filename="${a//$'\r'/}" # remove \r do windows
foldername=${filename%.*} # remove extensão (.pdf)
first_image_page=$(( $2 + $const0 )) # para transformar em JPEG
last_image_page=$(( $3 + $const1 )) # para transformar em JPEG
first_parse_page=$(( $2 - $const0 )) # para remover do TXT
last_parse_page=$3 # para remover do TXT
keyword="$4"
set -x
#obs rode: java -jar tika-server-1.19.jar -h 0.0.0.0 em outro terminal
#exemplo de utilização: bash run.sh SSP2.pdf 4 13 djikstra
python3 pdf_2txt.py $filename > out.txt
python3 pdf_2jpeg.py $filename $first_image_page $last_image_page
python3 txt_2cpp.py out.txt $foldername/ > test.txt
python3 images_2gif.py $foldername/images/
astyle $foldername/cpp/*.cpp
rm -rf $foldername/cpp/*.orig
python3 txt_2md.py test.txt $foldername/ $first_parse_page $last_parse_page > $foldername/$foldername.md
rm -rf *.txt
python3 generate_exercise_list.py
python3 add-exercises_2md.py "$keyword" $foldername/$foldername.md
