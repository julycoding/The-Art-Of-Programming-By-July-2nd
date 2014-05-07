def find_first_unique_char(string):
    if not string:
        return None
    chars = {}
    for s in string:
        if s in chars:
            chars[s] += 1
        else:
            chars[s] = 1
    for s in string:
        if chars[s] == 1:
            return s

if __name__ == '__main__':
    print find_first_unique_char('abababcababdddee')
    print find_first_unique_char('')
    print find_first_unique_char(None)
