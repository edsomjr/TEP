import sys
from itertools import takewhile


def factorization_2357(x):

    fs = [0]*10

    for p in [2, 3, 5, 7]:
        while x % p == 0:
            fs[p] += 1
            x //= p

    if x > 1:
        fs = []

    return fs


def solve(n):

    if len(n) == 1:
        return '1' + n

    fs = factorization_2357(int(n))

    if not fs:
        return 'There is no such number.'

    fs[9] = fs[3] // 2
    fs[3] %= 2

    fs[8] = fs[2] // 3
    fs[2] %= 3

    if fs[3] > 0 and fs[2] > 0:
        fs[6] = 1
        fs[2] -= 1
        fs[3] -= 1

    fs[4] = fs[2] // 2
    fs[2] %= 2

    x = 0

    for d in range(2, 10):
        while fs[d] > 0:
            x = 10*x + d
            fs[d] -= 1

    return str(x)


if __name__ == '__main__':

    ns = [x.strip() for x in sys.stdin.readlines()]
    ns = takewhile(lambda x: x != '-1', ns)
    xs = map(solve, ns)

    print('\n'.join(xs))
