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

# A simple version by @sfdye
def fib2(n):
    a = 0
    b = 1
    for i in xrange(n):
        a, b = b, a+b
    return a

print fib(10)
print fib2(10)