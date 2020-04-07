import sys

xs = [int(x) for x in sys.stdin.readlines()][:-1]
ans = ['1' if x % 17 == 0 else '0' for x in xs]

print('\n'.join(ans))
