from math import factorial as f

def binom(n, m):
    return f(n) // (f(n - m) * f(m))

def min_row(M):

    a = 0
    b = 64
    N = 64

    while a <= b:
        m = (a + b) // 2

        if binom(m, m // 2) >= M:
            N = m
            b = m - 1
        else:
            a = m + 1

    return N


if __name__ == '__main__':

    M = int(input())

    print(min_row(M))
