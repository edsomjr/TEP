while True:
    try:
        X, Y = map(int, input().split())

        print(X + Y)
    except EOFError:
        break
