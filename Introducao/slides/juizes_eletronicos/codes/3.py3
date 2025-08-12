while True:
    X, Y = map(int, input().split())

    if X == -1 and Y == -1:
        break

    print(X + Y)
