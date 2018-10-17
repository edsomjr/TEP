from tika import parser
import sys
import os

def main(argv):
    if len(argv) == 2:
        filename = argv[1]
        title = os.path.splitext(os.path.basename(filename))[0]
    else:
        print ('usage:\n    python pdf_2txt.py <txt>')
        return

    raw = parser.from_file(filename)
    xd = raw['content']
    xd = xd.split('\n')
    xd = list(filter(None, xd))

    for s in xd:
        print(s)

    return
if __name__ == '__main__':
    main(sys.argv)
