if __name__ == "__main__":
    n = 10000 * 500
    lst = [1 for i in xrange(n)]
    # better locality
    # using + basic arithmetic, faster than divide
    for i in xrange(2, n / 2):
        for j in xrange(2 * i, n, i):
            lst[j] += i
    for i in xrange(2, n):
        if lst[i] > i and lst[i] < n and lst[lst[i]] == i:
            print i, lst[i]
