#!/usr/bin/python3
import sys


if __name__ == '__main__':

    if len(sys.argv) < 4:
        print(f'Usage: {sys.argv[0]} start end code')
        sys.exit(-1)

    a = 0
    b = 8

    start = int(sys.argv[1])
    end = int(sys.argv[2])
    code = sys.argv[3]

    N = end - start + 1

    step = (b - a)/min(N - 1, 21)

    x = 1
    y = b
    count = 0

    lines = []

    for i in range(N):

        if count == 22:
            y = b - step
            x = 8

            print('vbar => Path')
            print('@vbar.path = (7.5, 8) -- (7.5, 0) -- cycle')
            print('@vbar.color = gray')
            print('&vbar.dashed')

        print(f'line{start} => Node')
        print(f'\t@line{start}.x = {x}')
        print(f'\t@line{start}.y = {y:.2f}')
        print('\t@line%d.text = \\inputline{c}{%d}{%s}' % (start, start, code))
        print(f'\t@line{start}.anchor = west')
        print()

        lines.append(f'-line{start}')

        y -= step
        start += 1
        count += 1

    print('\n'.join(lines))

