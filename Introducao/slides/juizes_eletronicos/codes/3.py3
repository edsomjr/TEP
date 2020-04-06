while True:
    line = input()
    X, Y = [int(n) for n in line.split()]

    if X == -1 and Y == -1:
        break

    print(X + Y)
