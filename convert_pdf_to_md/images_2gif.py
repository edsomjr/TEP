import imageio
import os
from os import listdir
from os.path import isfile, isdir, join
import sys

def main(argv):
    if len(argv) == 2:
        dir = argv[1]
        title = os.path.splitext(os.path.basename(dir))[0]
    else:
        print ('usage:\n    python images_2gif.py <pasta com imagens>')
        return

    vis_folders = [f for f in listdir(dir) if isdir(join(dir, f))]
    filenames = [[f for f in listdir(join(dir, v_fold)) if isfile(join(join(dir, v_fold), f))] for v_fold in vis_folders] 

    for i, vis in enumerate(vis_folders):
        images = []
        for filename in filenames[i]:
            images.append(imageio.imread(dir+vis+'/'+filename))
        imageio.mimsave(dir+vis+'/movie.gif', images, duration=2.4)

    return

if __name__ == '__main__':
    main(sys.argv)
