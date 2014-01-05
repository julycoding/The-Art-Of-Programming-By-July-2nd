def strreverse(s):
    s = list(s)
    s.reverse()
    return "".join(s)


def leftshift_5(s, n):
    n = n % len(s)
    head = strreverse(s[0:n])
    tail = strreverse(s[n:])
    ret = strreverse(head + tail)
    return ret

if __name__ == "__main__":
    s = "abcdef"
    n = 2
    print leftshift_5(s, n)
