#!/bin/bash
a=$1
y="${a//$'\r'/}"
x=${y%.*}
#obs run java -jar tika-server-1.19.jar -h 0.0.0.0 in another terminal
python3 pdf_2txt.py $y > out.txt && python3 pdf_2jpeg.py $y 6 16 && python3 txt_2cpp.py out.txt $x/ && python3 images_2gif.py $x/images/ && astyle $x/cpp/*.cpp && rm -rf $x/cpp/*.orig
