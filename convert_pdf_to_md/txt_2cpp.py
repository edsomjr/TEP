import os
import sys
import re

def main(argv):
    if len(argv) == 3:
        filename = argv[1]
        dir = argv[2]
        title = os.path.splitext(os.path.basename(filename))[0]
    else:
        print ('usage:\n    python txt_2cpp.py <txt> <dir>')
        return

    if not os.path.exists(dir+'cpp'):
        os.makedirs(dir+'cpp')

    f = open(filename, 'r')
    init = re.compile(r'Implementação')
    end = re.compile(r'return')
    alias = re.compile(r'\busing\b')
    reserved=r'(\balignas\b|\balignof\b|\band\b|\band_eq\b|\basm\b|\batomic_cancel\b|\batomic_commit\b|\batomic_noexcept\b|\bauto\b|\bbitand\b|\bbitor\b|\bbool\b|\bbreak\b|\bcase\b|\bcatch\b|\bchar\b|\bchar16_t\b|\bchar32_t\b|\bclass\b|\bcompl\b|\bconcept\b|\bconst\b|\bconstexpr\b|\bconst_cast\b|\bcontinue\b|\bco_await\b|\bco_return\b|\bco_yield\b|\bdecltype\b|\bdefault\b|\bdelete\b|\bdouble\b|\bdynamic_cast\b|\belse\b|\benum\b|\bexplicit\b|\bexport\b|\bextern\b|\bfalse\b|\bfloat\b|\bfriend\b|\bgoto\b|\bif\b|\bimport\b|\binline\b|\bint\b|\blong\b|\bmodule\b|\bmutable\b|\bnamespace\b|\bnew\b|\bnoexcept\b|\bnot\b|\bnot_eq\b|\bnullptr\b|\boperator\b|\bor\b|\bor_eq\b|\bprivate\b|\bprotected\b|\bpublic\b|\breflexpr\b|\bregister\b|\breinterpret_cast\b|\brequires\b|\breturn\b|\bshort\b|\bsigned\b|\bsizeof\b|\bstatic\b|\bstatic_assert\b|\bstatic_cast\b|\bstruct\b|\bswitch\b|\bsynchronized\b|\btemplate\b|\bthis\b|\bthread_local\b|\bthrow\b|\btrue\b|\btry\b|\btypedef\b|\btypeid\b|\btypename\b|\bunion\b|\bunsigned\b|\busing\b|\bvirtual\b|\bvoid\b|\bvolatile\b|\bwchar_t\b|\bwhile\b|\bxor\b|\bxor_eq\b|\=|\&|\||\%|\(|\)|\[|\]|\{|\}|\<|\>|\bstring\b'
    pattern_slide=r'(^\d)' # exemplo: [27 int z = x;]
    code = re.compile(pattern_slide+r'(.*?)'+reserved+r')')

    it = 0
    flag = False
    codes = ['']
    lines = f.readlines()

    for i, line in enumerate(lines):
        if alias.search(line):
            typdf = line.split(' ')[1]
            reserved += r'|\b%s\b' % typdf
            code = re.compile(pattern_slide+r'(.*?)'+reserved+r')')

        if flag == True and code.search(line):
            codes[it] += line.lstrip('0123456789 ')
            if end.search(line) and not code.search(lines[i+2]):
                flag = False
                codes[it] += '}'
                it += 1
                codes.append('')
                print('{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}')
        else:
            print(line, end='')

        if init.search(line):
            flag = True

    for i in range(0, len(codes)):
        if len(codes[i]):
            with open(dir+"cpp/code_{}.cpp".format(i), "w") as f:
                    f.write(codes[i])

    return
if __name__ == '__main__':
    main(sys.argv)
