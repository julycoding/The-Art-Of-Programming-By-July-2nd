#!/usr/bin/python
# -*- coding:utf-8 -*-

def find_first_unique_char(string):
    if string != None and len(string) > 0:
        chars = {}
        for i in range(0, len(string)):
            if string[i] in chars:
                chars[string[i]] += 1
            else:
                chars[string[i]] = 1
        for i in range(0, len(string)):
            if chars[string[i]] == 1:
                return string[i]
    return False

def main():
    string = 'abababcababdddee'
    print find_first_unique_char(string)
    return

if __name__ == '__main__':
    main()
