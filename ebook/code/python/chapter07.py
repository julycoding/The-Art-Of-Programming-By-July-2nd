#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
File: chapter07.1.py
Author: tdoly
Description: https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/07.0.md 求子数组的最大和
'''

def maxSum(ls):
    #判断列表
    if len(ls) > 0:
        #将列表的第一个元素赋值给result,用以判断全为负数的情况,mark初始值为0
        result, mark = ls[0], 0
    else:
        result = None
    for element in ls:
        #第一次循环，或者mark值为正数时，累加
        if mark >= 0:
            mark += element
        else:
            mark = element
        # 对比mark和result的值
        if mark > result:
            result = mark
    return result

def test():
    lss = [[1, -2, 3, 10, -4, 7, 2, -5],
           [1, 3, 10, -4, 7, 2],
           [-2, -2, -1, -1, -2],
           [-10, -3, -2, -14, 2],
           []
          ]
    for ls in lss:
        print maxSum(ls)

if __name__ == '__main__':
    test()
