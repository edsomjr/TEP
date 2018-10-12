while True:
    try:
        line = input()
        X, Y = [int(n) for n in line.split()]

        print(X + Y)
    except EOFError:
        break
