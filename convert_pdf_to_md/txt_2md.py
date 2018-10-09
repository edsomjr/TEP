from pdf2image import convert_from_path
import sys
import os
import re
import itertools
from collections import defaultdict
from os import listdir
from os.path import isfile, join

def main(argv):
    if len(argv) == 5:
        filename = argv[1]
        dir = argv[2]
        ini = int(argv[3]);
        fin = int(argv[4]);
        title = os.path.splitext(os.path.basename(filename))[0]
    else:
        print ('usage:\n    python txt_2md.py <txt> <diretorio com codigos> <pagina inicial> <pagina final>')
        return

    cpp_dir = dir+'cpp/'
    images_dir = dir+'images/'

    only_numbers = re.compile(r'^[\s\d]+$', re.U)
    not_only_numbers = re.compile(r'[^\W\d_]', re.U)
    code_flag = re.compile(r'{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}')
    codes = [join(cpp_dir, f) for f in listdir(cpp_dir) if isfile(join(cpp_dir, f))]
    it = 0
    lines = open(filename).readlines()
    flag = False

    d = defaultdict(lambda: 0)
    for i in range(1, len(lines)):
        if only_numbers.search(lines[i-1]) and not_only_numbers.search(lines[i]):
            current_page = int(lines[i-1].strip(' ').strip('\n'))
            if(current_page == ini):
                print('##', lines[i].strip(' ').strip('\n'))
                log = '![]({0}movie.gif)\nPara acessar álbum de imagens [clique aqui]({0}).'.format(images_dir)
                print(log)
            if(current_page < ini or current_page > fin):
                flag = True
            else:
                flag = False

        if flag == True and not_only_numbers.search(lines[i]) and not d[lines[i]]:
            line = lines[i].strip(' ').strip('\n').replace('•', '*')
            if only_numbers.search(lines[i-1]):
                line = "##"+line
            print(line)
            d[lines[i]] = 1

        if code_flag.search(lines[i]):
            code = open(codes[it], 'r')
            print('```C++')
            print(code.read())
            print('```')
            it+=1
            code.close()

    return
if __name__ == '__main__':
    main(sys.argv)
