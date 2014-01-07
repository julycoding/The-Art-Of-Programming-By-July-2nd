# -*- coding: utf-8 -*-
#!/usr/local/bin/python  

# 整体函数接口说明：
#
# Args:
# 	s: 给定需要移位的list
#	m: 需要移动的位数
#
# Returns:
# 	无。直接修改传入的list
#
# Author:
# 	Jasonwbw(Jasonwbw@yahoo.com)

import copy

##########################################################################
# Tools

def swap(s, i, j):
    '''交换s中i和i位置的元素
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor: 
    
    Args:
        s : 要交换的列表
	i : 索引位置i
	j : 索引位置j
    '''
    t = s[i]
    s[i] = s[j]
    s[j] = t

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
# see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E4%B8%80%E6%9A%B4%E5%8A%9B%E7%A7%BB%E4%BD%8D%E6%B3%95

def left_shift(s, m):
    '''循环m次左移1位
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:
    '''
    if m < 0 :
	raise Exception('m is less than 0')
    else:
	m = m % len(s)
    for i in xrange(m):
	left_shift_one(s, 0, len(s))

##########################################################################
# 思路二
# see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E4%BA%8C%E6%8C%87%E9%92%88%E7%BF%BB%E8%BD%AC%E6%B3%95

def pointer_flip_1(s, m):
    '''
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:
    '''
    if m < 0 :
	raise Exception('m is less than 0')
    else:
	m = m % len(s)
    
    n = len(s)
    for i in xrange((n - m) - n % m):
	swap(s, i, m + i)
    
    tail_head = (n / m - 1) * m
    for i in xrange(n % m):
	for j in xrange(m, 0, -1):
	    swap(s, i + j + tail_head, i + j + tail_head -1)

def pointer_flip_2(s, m):
    '''
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor:
    '''
    if m < 0 :
	raise Exception('m is less than 0')
    else:
	m = m % len(s)

    n = len(s)
    for i in xrange((n - m) - n % m):
	swap(s, i, m + i)

    tail_head = (n / m - 1) * m    # 例子中现在a的位置
    for i in xrange(n % m):
	# 交换n%m次
	swap(s, tail_head + i, tail_head + m + i)
    
    tail_head = tail_head + n % m  # 例子中现在c的位置
    for i in xrange((m - n % m) % m):
	# 后面m位，循环左移(m - n%m) % m
	left_shift_one(s, tail_head, n)

##########################################################################
# 思路三
# see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E4%B8%89%E9%80%92%E5%BD%92%E8%BD%AC%E6%8D%A2%E6%B3%95

def recur_tran(s, n, m, head, tail, flag = True):
    '''循环旋转
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor: 
    
    Args:
        n : 待处理部分的字符串长度
	m : 待处理部分的旋转长度
	head : 待处理部分的头指针
	tail : 待处理部分的尾指针
	flag : true进行左旋，flag = false进行右旋
    '''
    if head == tail or m <= 0:
	return

    k = n - m - n % m            # p1，p2移动距离
    p1 = flag and head or tail
    p2 = p1 + flag and m or -m
    step = flag and 1 or -1      # 左旋转step = 1, 右旋转step = -1
    
    for p1 in xrange(k):
	swap(s, p1, p2)
	p1 += step
	p2 += step
	
    if flag:
	recur_tran(s, n - k, n % m, p1, tail, flag = False)
    else:
	recur_tran(s, n - k, n % m, head, p1, flag = True)
	
def recur_tran_rotate(s, m):
    '''
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor: 
    '''
    recur_tran(s, len(s), m % len(s), 0, len(s) - 1)

##########################################################################
# 思路四
# see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E5%9B%9B%E5%BE%AA%E7%8E%AF%E7%A7%BB%E4%BD%8D%E6%B3%95

def recur_shifting(s, m):
    '''
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor: 
    '''
    from fractions import gcd
    n = len(s)
    gcd = gcd(n, m)
    
    for j in xrange(gcd):
	t = s[j]
	for i in xrange(n / gcd):
	    s[(j + i * m) % n] = s[(j + (i + 1) * m) % n]
	s[(j + i * m) % n] = t

def recur_shifting_v2(s, m):
    '''对上述方案4的改写。
    所有序号为 (i+t*k) % n (i为指定整数，t为任意整数)，....
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor: 
    '''
    from fractions import gcd
    n = len(s)
    gcd = gcd(n, m)
    
    for j in xrange(gcd):
	t = s[j]
	last = j
	# j+m为j右移gcd的位置，%n是当j+m>n时从左重新开始。
	i = (j + m) % n
	while i != j:
	    s[last] = s[i]
	    last = i
	    i = (i + m) % n
	    s[last] = t

##########################################################################
# 思路五
# see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md#%E6%80%9D%E8%B7%AF%E4%BA%94%E4%B8%89%E6%AD%A5%E7%BF%BB%E8%BD%AC%E6%B3%95

def invert(s, start, end):
    '''
    Author: Jasonwbw(Jasonwbw@yahoo.com)
    Editor: 
    '''
    n = end - start + 1
    for i in xrange(n / 2):
	t = s[start + i]
	s[start + i] = s[end - i]
	s[end - i] = t

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
    a1 = ['a','b','c','d','e','f','g','h','i']
    a2 = ['a','b','c','d','e','f','g','h']
    a3 = ['a','b','c','d','e','f','g']
    
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
    print ''

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
    print ''

    a2_1_1 = copy.copy(a1)
    a2_1_2 = copy.copy(a2)
    a2_1_3 = copy.copy(a3)
    a2_2_1 = copy.copy(a1)
    a2_2_2 = copy.copy(a2)
    a2_2_3 = copy.copy(a3)
    pointer_flip_1(a2_1_1, 3)
    pointer_flip_1(a2_1_2, 3)
    pointer_flip_1(a2_1_3, 3)
    pointer_flip_2(a2_2_1, 3)
    pointer_flip_2(a2_2_2, 3)
    pointer_flip_2(a2_2_3, 3)
    print 'pointer_flip_1:'
    print a2_1_1
    print a2_1_2
    print a2_1_3
    print 'pointer_flip_2:'
    print a2_2_1
    print a2_2_2
    print a2_2_3
    print ''

    a3_1 = copy.copy(a1)
    a3_2 = copy.copy(a2)
    a3_3 = copy.copy(a3)
    recur_tran_rotate(a3_1, 3)
    recur_tran_rotate(a3_2, 3)
    recur_tran_rotate(a3_3, 3)
    print 'recur_tran_rotate:'
    print a3_1
    print a3_2
    print a3_3
    print ''

    a4_1_1 = copy.copy(a1)
    a4_1_2 = copy.copy(a2)
    a4_1_3 = copy.copy(a3)
    a4_2_1 = copy.copy(a1)
    a4_2_2 = copy.copy(a2)
    a4_2_3 = copy.copy(a3)
    recur_shifting(a4_1_1, 3)
    recur_shifting(a4_1_2, 3)
    recur_shifting(a4_1_3, 3)
    recur_shifting_v2(a4_2_1, 3)
    recur_shifting_v2(a4_2_2, 3)
    recur_shifting_v2(a4_2_3, 3)
    print 'recur_shifting:'
    print a4_1_1
    print a4_1_2
    print a4_1_3
    print 'recur_shifting_v2:'
    print a4_2_1
    print a4_2_2
    print a4_2_3
    print ''

    a5_1 = copy.copy(a1)
    a5_2 = copy.copy(a2)
    a5_3 = copy.copy(a3)
    invert_solution(a5_1, 3)
    invert_solution(a5_2, 3)
    invert_solution(a5_3, 3)
    print 'invert_solution:'
    print a5_1
    print a5_2
    print a5_3
    print ''
