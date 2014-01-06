#!/usr/bin/python
# -*- coding:utf-8 -*-

def find_sum(array, key):
    if len(array) > 0:
        array = sorted(array)
        start = 0
        end = len(array) - 1
        while start < end:
            result = array[start] + array[end]
            if result > key:
                end -= 1
            elif result < key:
                start += 1
            else:
                return [array[start], array[end]]
    return False

def main():
    array = [4, 2, 1, 7, 11, 15]
    key = 15
    print find_sum(array, key)
    return

if __name__ == '__main__':
    main()
