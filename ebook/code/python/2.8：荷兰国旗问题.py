#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Title: 荷兰国旗问题
Author: sumnous
Created on: 2014-05-31
"""

def threeFlag(array, begin, current, end):
    while current <= end:
        if array[current] == 0:
            array[begin], array[current] = array[current], array[begin]
            current += 1
            begin += 1
        elif array[current] == 1:
            current += 1
        elif array[current] == 2:
            array[current], array[end] = array[end], array[current]
            end -= 1

if __name__ == "__main__":
    array = [0, 0, 1, 1, 1, 2, 0, 2, 1, 2]
    threeFlag(array, 0, 0, len(array) - 1)
    print array