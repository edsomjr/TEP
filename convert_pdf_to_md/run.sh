#!/bin/bash
shopt -s extglob
if [ "$#" -ge 6 ] ; then
    const0=1;
    const1=2;
    a=$1; # ex: SSP-2.pdf
    filename="${a//$'\r'/}"; # remove \r do windows
    foldername=${filename%.*}; # remove extensão (.pdf)
    last_page_file=$2;
    keyword="$3";
    num_vis=$4;
    tot=$(($num_vis*2 + 4));
    if [[ "$#" -eq "tot" ]]; then
        img_page=();
        parse_page=();
        for ((i=5;i<=$#;i+=2)); do
            next=$(($i+1));

            img_page+=($((${!i}+1)));
            img_page+=($((${!next}+2)));

            parse_page+=($((${!i}-1)));
            parse_page+=($((${!next})));
        done;

        set -x;
        #obs rode: java -jar tika-server-1.19.jar -h 0.0.0.0 em outro terminal
        #exemplo de utilização: bash run.sh SSP-2.pdf 22 djikstra 1 4 13
        python3 pdf_2txt.py $filename > test.txt;
        python3 correct_words.py test.txt > out.txt;
        python3 pdf_2jpeg.py $filename $num_vis ${img_page[@]};
        python3 txt_2cpp.py out.txt $foldername/ > flagged.txt;
        python3 images_2gif.py $foldername/images/;
        astyle $foldername/cpp/*.cpp;
        rm -rf $foldername/cpp/*.orig;
        python3 txt_2md.py flagged.txt $foldername/ $last_page_file $num_vis ${parse_page[@]} > $foldername/$foldername.md;
        rm !(!(*.txt)|category_count.txt);
        # python3 generate_exercise_list.py; # descomentar caso queira atualizar o 'banco'
        python3 add-exercises_2md.py "$keyword" $foldername/$foldername.md;
        echo "bash run.sh $@" > make-$foldername.sh;
    else
        printf "Numero de parametros errados.\nExemplo de uso: bash run.sh SSP-2.pdf 22 djikstra 1 4 13\n[Leia o README em caso de dúvida]\n"
    fi
else
    printf "Numero de parametros errados.\nExemplo de uso: bash run.sh SSP-2.pdf 22 djikstra 1 4 13\n[Leia o README em caso de dúvida]\n"
fi
