#!/usr/bin/python
# -*- coding:utf-8 -*-

def more_than_half_number(array):
    if len(array) > 0:
        count = 1
        value = array[0]
        for i in range(1, len(array) - 1):
            if array[i] == value:
                count += 1
            else:
                count -= 1
                if count == 0:
                    value = array[i]
                    count = 1
        count = sum([1 for item in array if item == value])
        if count * 2 > len(array):
            return value
    return False

def main():
    result = more_than_half_number([0, 3, 1, 3, 2, 3, 4, 3, 3, 3])
    print result
    return

if __name__ == '__main__':
    main()
