from pdf2image import convert_from_path
import sys
import os

def main(argv):
    if len(argv) == 4:
        filename = argv[1]
        ini = int(argv[2]) - 1;
        fin = int(argv[3]) - 1;
        title = os.path.splitext(os.path.basename(filename))[0]
        print ('Parsing', filename)
    else:
        print ('usage:\n    python pdf_2jpeg.py <pdf> <pagina inicial> <pagina final>')
        return

    directory = filename.strip('.pdf') + '/images'
    pages = convert_from_path(filename, 500)

    if not os.path.exists(directory):
        os.makedirs(directory)

    for i in range(ini, min(fin, len(pages))):
        pages[i].save(directory+'/out'+str(i)+'.jpg', 'JPEG')

    return
if __name__ == '__main__':
    main(sys.argv)
