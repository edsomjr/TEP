from pdf2image import convert_from_path
import sys
import os

def main(argv):
    if len(argv) >= 4:
        num_vis = int(argv[2])
        if len(argv) == num_vis*2 + 3:
            filename = argv[1]
            ini = []
            fin = []
            it = 3
            for i in range(0, num_vis):
                ini.append(int(argv[it]))
                fin.append(int(argv[it+1]))
                it+=2
        else:
            print ('usage:\n    python pdf_2jpeg.py <pdf> <numero de visualizaçoes> <pagina inicial 1> <pagina final1> ... <pagina inicial N> <pagina final N>')
            return
    else:
        print ('usage:\n    python pdf_2jpeg.py <pdf> <numero de visualizaçoes> <pagina inicial 1> <pagina final1> ... <pagina inicial N> <pagina final N>')
        return

    directory = filename.strip('.pdf') + '/images'
    pages = convert_from_path(filename, 500)

    if not os.path.exists(directory):
        os.makedirs(directory)

    for i in range(0, num_vis):
        current_dir = directory+'/vis-'+str(i)
        if not os.path.exists(current_dir):
            os.makedirs(current_dir)
        for j in range(ini[i], fin[i]):
            pages[j].save(current_dir+'/out'+(str(j).zfill(2))+'.jpg', 'JPEG')

    return
if __name__ == '__main__':
    main(sys.argv)
