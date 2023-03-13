import sys


fibs = [1, 2]

while len(fibs) <= 101:
    fibs.append(fibs[-1] + fibs[-2])


def to_decimal(n):

    ys = list(map(lambda x: int(x), n))[::-1]

    return sum(map(lambda x, y: x*y, fibs, ys))


def to_fibinary(n):

    if n == 0:
        return '0\n'

    res = []

    for fib in fibs[::-1]:
        if fib <= n:
            n -= fib
            res.append('1')
        else:
            res.append('0')

    return ''.join(res).lstrip('0') + '\n'


def fibinary_sum(p):

    a, b = p
    n = to_decimal(a) + to_decimal(b)
    return to_fibinary(n)


def solve(xs):

    return map(lambda p: fibinary_sum(p), xs)


if __name__ == '__main__':

    xs = [x.strip() for x in sys.stdin.readlines() if x.strip()]
    xs = list(zip(xs[::2], xs[1::2]))
    print('\n'.join(solve(xs)), end='')
