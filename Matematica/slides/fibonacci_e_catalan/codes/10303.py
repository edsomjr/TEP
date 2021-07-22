import sys
import math


def catalan(n):
    return str(math.factorial(2*n)//((n + 1)*math.factorial(n)**2))

def solve(ns):
    return map(catalan, ns)

if __name__ == '__main__':
    xs = sys.stdin.readlines()
    ns = map(int, xs)
    ans = solve(ns)

    print('\n'.join(ans))
