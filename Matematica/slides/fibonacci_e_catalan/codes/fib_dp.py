fib = [0, 1]

def fibonacci(n):
    if n < len(fib) + 1:
        return fib[n]

    next = len(fib)

    while next <= n:
        fib.append(fib[next - 1] + fib[next - 2])
        next += 1

    return fib[n]
