import math


def prime_list(n):
    lst = range(0, n + 1)
    lst[1] = 0
    thres = int(math.sqrt(n))
    for i in xrange(2, thres + 1):
        if lst[i] == 0:
            continue
        for j in range(i * 2, len(lst), i):
            lst[j] = 0
    return [i for i in lst if i != 0]


def sum_divisors(n, primelst):
    s = 1
    for p in primelst:
        if p * p > n:
            break
        if n % p == 0:
            j = p * p
            n = n / p
            while n % p == 0:
                j = j * p
                n = n / p
            s = s * (j - 1) / (p - 1)
    if n > 1:
        s = s * (n + 1)
    return s


def get_sum_div(n, primelst):
    return sum_divisors(n, primelst) - n

if __name__ == "__main__":
    N = 500 * 10000
    primelst = prime_list(N)
    for n in range(2, N + 1):
        m = get_sum_div(n, primelst)
        if m > n:
            nn = get_sum_div(m, primelst)
            if n == nn:
                print n, m
