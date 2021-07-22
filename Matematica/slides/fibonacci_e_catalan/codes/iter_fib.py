def iterative_fibonacci(n):
    if n < 2:
        return n

    a = 0
    b = 1

    for _ in range(n):
        a, b = b, a + b

    return a
