import os
import sys
from symspellpy.symspellpy import SymSpell, Verbosity  # import the module
from collections import defaultdict

def main(argv):
    if len(argv) == 3:
        category = argv[1]
        markdown = argv[2]
    else:
        print ('usage:\n    python .py "<categoria>" <markdown gerado>')
        return
    initial_capacity = 83000
    max_edit_distance_dictionary = 3
    prefix_length = 7
    sym_spell = SymSpell(initial_capacity, max_edit_distance_dictionary, prefix_length)
    dictionary_path = "category_count.txt"
    term_index = 0  # column of the term in the dictionary text file
    count_index = 1  # column of the term frequency in the dictionary text file

    if not sym_spell.load_dictionary(dictionary_path, term_index, count_index):
        print("Dictionary file not found")
        return

    categorys = open(dictionary_path, 'r')
    d = defaultdict(lambda: 0)
    for x in categorys.readlines():
        z = x.split(' ')
        d[z[0]] = z[2]

    f = open(markdown, 'a')
    f.write('\n## Lista de Exercicios - %s\n' % (category))
    suggestion_verbosity = Verbosity.CLOSEST  # TOP, CLOSEST, ALL
    inputs = category.split(' ')
    total_avg = sum( map(len, inputs) ) / len(inputs)

    max_edit_distance_lookup = 3 if total_avg > 3 else 2
    for input_term in inputs:
        suggestions = sym_spell.lookup(input_term, suggestion_verbosity, max_edit_distance_lookup)
        for suggestion in suggestions:
            f.write("* {}, https://a2oj.com/{}".format((suggestion.term).capitalize(), d[suggestion.term]))

    f.close()
    categorys.close()

if __name__ == "__main__":
    main(sys.argv)
