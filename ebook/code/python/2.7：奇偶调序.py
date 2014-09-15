#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Title: 奇偶调序
Author: sumnous
Created on: 2014-05-31
"""

def isOddNumber(data):
    return data & 1 == 1

def oddEvenSort1(data, length):
    if length == 0:
        return
    begin = 0
    end = length -1
    while begin < end:
        if isOddNumber(data[begin]):
            begin += 1
        elif not isOddNumber(data[end]):
            end -= 1
        else:
            data[begin], data[end] = data[end], data[begin]

def oddEvenSort2(data, lo, hi):
    i = lo -1
    for j in xrange(lo, hi):
        if isOddNumber(data[j]):
            i = i + 1
            data[i], data[j] = data[j], data[i]
    data[i+1], data[hi] = data[hi], data[i+1]

def reverse(data, length):
    if length < 2:
        return
    i = 0
    j = length - 1
    while i < j:
        data[i], data[j] = data[j], data[i]
        i += 1
        j -= 1

def reverseStable(data, length, p):
    #print "1", data
    reverse(data, length)
    #print "2", data
    reverse(data, length - p)
    #print "3", data
    reverse(data[length-p:], p)
    #print "4", data
    return data

def posiNegaSort(data, length):
    # 一个未排序整数数组，有正负数，重新排列使负数排在正数前面，并且要求不改变原来的正负数之间相对顺序。
    # 比如：input: 1,7,-5,9,-12,15 ans: -5,-12,1,7,9,15 要求时间复杂度O(n)，空间O(1)。
    # Link: http://blog.csdn.net/qianquanyiyan/article/details/7478834, 平均时间复杂度O(n^2), 最好情况O(n)
    n0 = length - 1
    while n0 > 0:
        while n0 > 0 and data[n0] > 0:
            n0 -= 1
        n1 = n0
        while n1 - 1 >= 0 and data[n1-1] < 0:
            n1 -= 1
        p0 = n1 - 1
        p1 = p0
        while p1 - 1 > 0 and data[p1-1] >= 0:
            p1 -= 1
        #print [n0, n1, p0, p1]
        if n1 > 0 and p1 >= 0:
            data[p1:] = reverseStable(data[p1:], n0 - p1 + 1, p0 - p1 + 1)
        else:
            break
        n0 -= 1

if __name__ == '__main__':
    # 解法1
    data = [2, 8, 7, 1, 3, 5, 6, 4]
    length = len(data)
    oddEvenSort1(data, length-1)
    print data
    # 解法2
    data = [2, 8, 7, 1, 3, 5, 6, 4]
    oddEvenSort2(data, 0, length-1)
    print data
    # 正负排序，不变换相对位置，平均时间复杂度O(n^2)，空间复杂度O(1)
    data = [1, 7, -5, 9, -12, 15]
    posiNegaSort(data, len(data))
    print data