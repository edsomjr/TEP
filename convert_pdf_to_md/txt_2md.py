from pdf2image import convert_from_path
import sys
import os
import re
import itertools
from collections import defaultdict
from os import listdir
from os.path import isfile, join
from math import inf

def main(argv):
    if len(argv) >= 6:
        num_vis = int(argv[4])
        if len(argv) == num_vis*2 + 5:
            filename = argv[1]
            dir = argv[2]
            last_page = int(argv[3])
            ini = []
            fin = []
            it = 5
            for i in range(0, num_vis):
                ini.append(int(argv[it]))
                fin.append(int(argv[it+1]))
                it+=2
            ini.append(inf)
            fin.append(inf)
        else:
            print ('usage:\n    python txt_2md.py <txt> <diretorio do pdf> <pagina final documento> <numero de visualizaçoes> <pagina inicial vis 1> <pagina final vis1> ... <pagina inicial vis N> <pagina final vis N>')
            return
    else:
        print ('usage:\n    python txt_2md.py <txt> <diretorio do pdf> <pagina final documento> <numero de visualizaçoes> <pagina inicial vis 1> <pagina final vis1> ... <pagina inicial vis N> <pagina final vis N>')
        return

    cpp_dir = dir+'cpp/'
    images_dir = 'images/'

    only_numbers = re.compile(r'^[\s\d]+$', re.U)
    not_only_numbers = re.compile(r'[^\W\d_]', re.U)
    code_flag = re.compile(r'{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}')
    codes = [join(cpp_dir, f) for f in listdir(cpp_dir) if isfile(join(cpp_dir, f))]
    it = 0
    lines = open(filename).readlines()
    flag = False
    vis_it = 0
    d = defaultdict(lambda: 0)

    for i in range(1, len(lines)):
        if only_numbers.search(lines[i-1]) and not_only_numbers.search(lines[i]):
            current_page = int(lines[i-1].strip(' ').strip('\n'))
            if(current_page < ini[vis_it] or current_page > fin[vis_it]):
                flag = True
            else:
                flag = False
            if(current_page+1 == fin[vis_it]):
                print('## ', lines[i].strip(' ').strip('\n'))
                log = '![]({0}movie.gif)\nPara acessar álbum de imagens [clique aqui]({0}).\n'.format(images_dir+'vis-'+str(vis_it)+'/')
                print(log)
                vis_it+=1
                d[lines[i]] = 1
            if(current_page >= last_page):
                flag = False

        if flag == True and not_only_numbers.search(lines[i]) and not d[lines[i]]:
            line = lines[i].strip(' ').strip('\n').replace('•', '*')
            if only_numbers.search(lines[i-1]):
                line = "## "+line
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
