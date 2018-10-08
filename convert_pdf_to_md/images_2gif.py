import imageio
import os
from os import listdir
from os.path import isfile, join
import sys

def main(argv):
    if len(argv) == 2:
        dir = argv[1]
        title = os.path.splitext(os.path.basename(dir))[0]
        print ('Parsing', dir)
    else:
        print ('usage:\n    python images_2gif.py <pasta com imagens>')
        return

    filenames = [f for f in listdir(dir) if isfile(join(dir, f))]

    images = []
    for filename in filenames:
        images.append(imageio.imread(dir+filename))
    imageio.mimsave(dir+'movie.gif', images, duration=2.4)

    return

if __name__ == '__main__':
    main(sys.argv)
