import sys
import os
import unicodedata

def main(argv):
    if len(argv) == 2:
        filename = argv[1]
    else:
        print ('usage:\n    python add_accent.py <text>')
        return

    file = open(filename, 'r')

    for line in file.readlines():
        words = line.strip('\n').split(' ')
        words = list(filter(None, words))
        for i, word in enumerate(words):
            word = unicodedata.normalize('NFKD', word)
            if 'ı' in word:
                bad = '́'+ 'ı'
                word = word.replace(bad, 'í')
            if '6=' in word:
                word = word.replace('6=', '!=')
            print(word, end=' ' if i+1<len(words) else '\n')

    file.close()
    return

if __name__ == '__main__':
    main(sys.argv)
