# -*- coding: utf-8 -*-
import copy

# 整体函数接口说明：
#
# Args:
#   s: 给定需要移位的list
#   m: 需要移动的位数
#
# Returns:
#   无。直接修改传入的list
#
# Author:
#   Jasonwbw(Jasonwbw@yahoo.com)

##########################################################################
# Tools


def left_shift_one(s, i, j):
    '''s从i(包含)到j(不包含)，左移一位
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:

    Args:
        s : 给定需要移位的list
        i : 索引位置i
        j : 索引位置j
    '''
    t = s[i]
    for k in xrange(i, j - 1):
        s[k] = s[k + 1]
    s[j - 1] = t

##########################################################################
# 思路零
# python语言基础思路


def simple_shift(s, m):
    '''python对于list类型的s,最适合的暴力方法是直接选取两部分的字符串直接拼接
    Author:Jasonwbw(Jasonwbw@yahoo.com)
    Editor:
    '''
    if m < 0:
        raise Exception('m is less than 0')
    if len(s) <= m:
        m = m % len(s)
    t = copy.copy(s)
    del s[:]
    s += t[m:] + t[:m]

##########################################################################
# 思路一
# see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E4%B8%80%E6%9A%B4%E5%8A%9B%E7%A7%BB%E4%BD%8D%E6%B3%95


def left_shift(s, m):
    '''循环m次左移1位
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:
    '''
    if m < 0:
        raise Exception('m is less than 0')
    else:
        m = m % len(s)
    for i in xrange(m):
        left_shift_one(s, 0, len(s))

##########################################################################
# 思路二
# see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E4%BA%8C%E4%B8%89%E6%AD%A5%E7%BF%BB%E8%BD%AC%E6%B3%95


def invert(s, start, end):
    '''Invert the list s from start to end(contained).
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:

    Args:
        s : 要翻转的list
        start : 翻转的起始位置
        end : 翻转的结束位置(包含)
    '''
    n = end - start + 1
    for i in xrange(n / 2):
        s[start + i], s[end - i] = s[end - i], s[start +i]


def invert_solution(s, m):
    '''
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:
    '''
    n = len(s)
    invert(s, 0, m - 1)
    invert(s, m, n - 1)
    invert(s, 0, n - 1)

##########################################################################

if __name__ == '__main__':
    a1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
    a2 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    a3 = ['a', 'b', 'c', 'd', 'e', 'f', 'g']

    a0_1 = copy.copy(a1)
    a0_2 = copy.copy(a2)
    a0_3 = copy.copy(a3)
    simple_shift(a0_1, 3)
    simple_shift(a0_2, 3)
    simple_shift(a0_3, 3)
    print 'simple_shift:'
    print a0_1
    print a0_2
    print a0_3
    print

    a1_1 = copy.copy(a1)
    a1_2 = copy.copy(a2)
    a1_3 = copy.copy(a3)
    left_shift(a1_1, 3)
    left_shift(a1_2, 3)
    left_shift(a1_3, 3)
    print 'left_shift:'
    print a1_1
    print a1_2
    print a1_3
    print

    a2_1 = copy.copy(a1)
    a2_2 = copy.copy(a2)
    a2_3 = copy.copy(a3)
    invert_solution(a2_1, 3)
    invert_solution(a2_2, 3)
    invert_solution(a2_3, 3)
    print 'invert_solution:'
    print a2_1
    print a2_2
    print a2_3
    print
