header = '''
\\begin{frame}[fragile]{Problema}
    \\begin{figure}[!ht]
        \\begin{tikzpicture}
'''

trailer = '''
        \\end{tikzpicture}
    \\end{figure}
\\end{frame}
'''

hs = [5, 3, 6, 10, 5, 5, 8, 6, 11, 9, 10, 3, 6, 1, 9, 4, 5, 6, 10, 10, 10, 3, 2, 8,
    3, 11, 4, 9, 1, 6, 5, 4, 8]

if __name__ == '__main__':

    print(header)

    outline = []

    x = 0.0
    y = 0.0
    step = 0.3

    for h in hs:
        h /= 2.0

        print(f'\\draw[dotted] ({x}, 0) rectangle ({x + step}, {h});')

        outline.append((x, h))
        outline.append((x + step, h))

        x += step
        y = h

    print(f'\\draw ({-2*step}, {1.5/2}) -- ({x + 2*step}, {1.5/2})' + ' node[anchor=west] { \\scriptsize \\bf 4 };')
    print(f'\\draw ({-2*step}, {4.5/2}) -- ({x + 2*step}, {4.5/2})' + ' node[anchor=west] { \\scriptsize \\bf 11 };')
    print(f'\\draw ({-2*step}, {7.5/2}) -- ({x + 2*step}, {7.5/2})' + ' node[anchor=west] { \\scriptsize \\bf 10 };')
    print(f'\\draw ({-2*step}, {10.5/2}) -- ({x + 2*step}, {10.5/2})' + ' node[anchor=west] { \\scriptsize \\bf 3 };')
    print('\\node[anchor=north] at (0, 0) { \\scriptsize \\bf 1 };')
    print(f'\\node[anchor=north] at ({x}, 0)' + ' { \\scriptsize \\bf 33 };')

    outline.append((x, 0))
    outline.append((0, 0))

    s = '\\draw[thick] (0, 0)'

    for x, y in outline:
        s += f' -- ({x}, {y})'

    print(s + ';')

    print(trailer)
