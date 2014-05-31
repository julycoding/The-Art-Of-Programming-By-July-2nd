#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Title: 寻找和为定值的多个数
Author: sumnous
Created on: 2014-05-30
"""

list1 = []
def sumOfkNumber1(sum, n):
    # list1(sum,n)= list1(sum-n,n-1)+list1(sum,n-1) 取n和不取n的情况
    if n <= 0 or sum <= 0:
        return
    if sum == n:
        list1.reverse()
        if list1 == []:
            print n
        else:
            print n, " + ", " + ".join(str(x) for x in list1)
        list1.reverse()
    list1.append(n)
    sumOfkNumber1(sum - n, n - 1) #
    list1.pop()
    sumOfkNumber1(sum, n - 1)

def sumOfkNumber2(t, k, r, M, flag, X):
    # 回溯法+剪枝，其中X数组是解向量
    X[k] = True # 选第k个数
    if t + k == M: # 若找到一个和为M，则设置解向量的标志位，输出解
        flag = True
        print [i for i in xrange(1, k+1) if X[i] == 1]
    else:
        # 若第k+1个数满足条件，则递归左子树
        if t + k + (k + 1) <= M:
            sumOfkNumber2(t + k, k +1, r - k, M, flag, X)
        # 若不选第k个数，选第k+1个数满足条件，则递归右子树
        if t + r - k >= M and t + (k + 1) <=M:
            X[k] = False
            sumOfkNumber2(t, k + 1, r - k, M, flag, X)

def search(M, N):
    # 初始化解空间
    sum = (N + 1) * N * float(0.5)
    if M < 1 or M > sum:
        print "not found\n"
        return
    f = False
    X = {}
    sumOfkNumber2(0, 1, sum, M, f, X)
    if not f:
        print "not found\n"

def zeroOnePack(c, w, n, v):
    # 0-1背包问题
    # 用子问题定义状态：即f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。
    # 则其状态转移方程便是：f[i][v] = max{f[i-1][v], f[i-1][v-c[i]] + w[i]}
    f = [[-1 for j in range(v + 1)] for i in range(n + 1)]
    for j in xrange(v + 1):
        f[0][j] = 0
    for i in xrange(1, n + 1):
        for j in xrange(1, v + 1):
            f[i][j] = f[i-1][j]
            if j >= c[i-1]:
                f[i][j] = max(f[i-1][j], f[i-1][j-c[i-1]] + w[i-1])
    return f

def show(n, v, c, f):
    print "最大价值为: ", f[n][v]
    x = [0 for i in range(n)]
    j = v
    for i in range(1, n + 1):
        if f[i][j] > f[i-1][j]:
            x[i-1] = 1
            j -= c[i-1]
    print "选择物品的解为: ", x

if __name__ == '__main__':
    # 解法1
    sumOfkNumber1(6, 8)
    # 解法2
    search(6, 8)
    # 0-1背包问题
    n = 5
    v = 10
    c = [2, 2, 6, 5, 4]
    w = [6, 3, 5, 4, 6]
    res = zeroOnePack(c, w, n, v)
    show(n, v, c, res)
