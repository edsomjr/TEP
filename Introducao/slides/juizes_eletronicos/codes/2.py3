T = int(input())

for _ in range(T):
    line = input()
    X, Y = [int(n) for n in line.split()]

    print(X + Y)
