a = 0
b = 8

start = 8
end = 28
N = end - start + 1

code = 'codes/sub3.c'

step = (b - a)/(N - 1)

for i in range(N):
    print(f'line{start} => Node')
    print(f'\t@line{start}.x = 1')
    print(f'\t@line{start}.y = {b:.2f}')
    print('\t@line%d.text = \\inputline{c}{%d}{%s}' % (start, start, code))
    print(f'\t@line{start}.anchor = west')
    print()

    b -= step
    start += 1
