def strstr(haystack, needle):
    return any(
        all((haystack[i + j] == needle[j] for j in xrange(0, len(needle))))
        for i in xrange(0, len(haystack) - len(needle) + 1))


def test_strstr():
    print "test_strstr"
    print strstr("abcdf", "cd") is True
    print strstr("abcdf", "ef") is False


def find_no_repeat_char(string):
    maxchar = 256
    charlst = [0 for i in xrange(maxchar)]
    for c in string:
        charlst[ord(c)] += 1
    for i in xrange(0, maxchar):
        if charlst[i] == 1:
            return chr(i)


def test_find_no_repeat_char():
    print "test_find_no_repeat_char"
    s = "abaccdeff"
    print find_no_repeat_char(s) is "b"


if __name__ == "__main__":
    test_strstr()
    test_find_no_repeat_char()
