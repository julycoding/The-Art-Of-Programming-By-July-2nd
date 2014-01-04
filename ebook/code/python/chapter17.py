def fib(n):
    a, b, p, q = 1, 0, 0, 1
    while n != 0:
        if n % 2 == 0:
            p, q = p * p + q * q, 2 * p * q + q * q
            n = n / 2
        else:
            a, b = b * q + a * q + a * p, b * p + a * q
            n -= 1
    return b

print fib(10)
