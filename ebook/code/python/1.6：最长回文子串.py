#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Title: 求最长回文子串
Author: Fred Akalin
Link: http://www.akalin.cx/longest-palindrome-linear-time
"""

import sys

xrange = xrange if sys.version_info < (3,) else range

def fastLongestPalindromes(seq):
    """
    行为跟 naiveLongestPalindromes(如下) 相同, 但是时间复杂度 O(n).
    """
    seqLen = len(seq)
    l = []
    i = 0
    palLen = 0
    # 循环不变量: seq[(i - palLen):i] 是一个回文串.
    # 循环不变量: len(l) >= 2 * i - palLen. 增加 palLen 的代码跳过了 l
    # 填充的内部循环.
    # 循环不变量: len(l) < 2 * i + 1. 任何 seqLen - 1 之后增加 i
    # 的代码早早的退出了循环, 所以也跳过了 l 填充的内部循环.
    while i < seqLen:
        # 首先, 看我们是否可以扩展当前的回文串. 注意回文串的中心保持不变.
        if i > palLen and seq[i - palLen - 1] == seq[i]:
            palLen += 2
            i += 1
            continue

        # 当前的回文串是能获取的最大回文串, 所以加入 l.
        l.append((palLen, seq[(i - palLen):i]))

        # 现在为了更进一步, 我们寻找一个跟当前回文串共享右边缘的更小的回文串.
        # 如果我们找到一个, 我们尽量扩展它并且看它能把我们带到哪. 同时,
        # 我们可以为上面循环中我们忽略的 l 填充值.
        # 我们利用前面回文串(palLen)长度的知识以及回文串右半边 l
        # 位置的值跟回文串左半边对称位置的值密切相关这一事实.

        # 从第二到最后一个索引开始到上一个回文的边缘向后遍历.
        s = len(l) - 2
        e = s - palLen
        for j in xrange(s, e, -1):
            # d 是为了跟上一个回文串共享左边缘的中心的回文串 l[j] 必须有的值
            # (画出来可能有助于理解为什么这个地方 -1).
            d = j - e - 1

            # 我们检查看看在 l[j] 处的回文串是否和上一个回文串共享左边缘.
            # 如果这样, 右半边对称的回文串必定跟上一个回文串共享右边缘,
            # 所以我们给 palLen 一个新值.

            # 在这里读者可能会想到把 == 替换为 =>, 这不会影响算法正确性,
            # 但会影响性能. 想想为什么?
            if l[j] == d:
                palLen = d
                # 我们确实想回到外部循环的开始处, 但是 Python
                # 没有循环标签(类似于 goto). 作为替代, 我们用一个 else
                # 块对应内循环, 它仅当 for 循环正常退出时才执行(不是通过
                # break).
                break

            # 否则, 我们仅拷贝值到右边. 我们不得不绑定 l[i]
            # 因为左边的回文串可以扩展超过上一个回文串的左边缘,
            # 而他们地对称部分不能扩展超过右边缘.
            l.append((min(d, l[j][0]), seq[(i - palLen):i]))
        else:
            # 下面的代码在两种情况下执行: for 循环没有执行(palLen == 0)
            # 或者内部循环没有找到一个回文串跟上一个回文串共享左边界.
            # 不管哪种情况, 我们都无需考虑处于 seq[i] 中心的回文串.
            palLen = 1
            i += 1

    # 我们从循环不变量中得知: len(l) < 2 * seqLen + 1, 所以我们必须填充 l
    # 剩余的值.

    # 明显地, 我们寻找地上一个回文串不再增加.
    l.append((palLen, seq[(i - palLen):i]))

    # 从第二到最后一个索引开始递增向后遍历直到我们使 l 的大小增加到 2 *
    # seqLen + 1. 我们能从循环不变量中推断我们有足够的元素.
    lLen = len(l)
    s = lLen - 2
    e = s - (2 * seqLen + 1 - lLen)
    for i in xrange(s, e, -1):
        # d 使用了跟上面内部循环一样地公式(计算到上一个回文串左边缘地距离).
        d = i - e - 1
        # 我们将 l[i] 跟 min 绑定是出于跟上面地内部循环同样地原因.
        l.append((min(d, l[i][0]), seq[(i - palLen):i]))

    return l

def naiveLongestPalindromes(seq):
    """
    给定一个序列 seq, 返回一个列表 l 使得:

    l[2*i+1] 持有中心位置在 seq[i] 最大回文串的长度(必定是奇数);
    l[2*i] 持有中心位置介于 seq[i-1] 和 seq[i] 之间最大回文串的长度(必定是偶数);
    l[2*len(seq)] 持有中心位置在 seq 最后一个元素之后最大回文串的长度(必定是 0, 即 l[0]);

    对于 l[i] 来说, 实际的回文串是 seq[s:(s+l[i])], 此时 s 等于 i // 2 - l[i] // 2(// 是整除).

    示例:
    naiveLongestPalindrome('ababa') -> [0, 1, 0, 3, 0, 5, 0, 3, 0, 1]

    时间复杂度: O(n^2).
    """
    seqLen = len(seq)
    lLen = 2 * seqLen + 1
    l = []

    for i in xrange(lLen):
        # 如果 i 是偶数(我们处在空格上, 想像一下在 seq 首尾以及元素间插入空格), 这时 e == s;
        # 否则我们处在 seq 的一个元素上, 作为回文串上单个的字符.
        s = i // 2
        e = s + i % 2

        # 循环不变量: seq[s:e] 是一个回文串.
        while s > 0 and e < seqLen and seq[s - 1] == seq[e]:
            s -= 1
            e += 1

        l.append((e - s, seq[s:e]))

    return l


# implement manacher algorithm
def pre_process(seq):
  res = ['#{}'.format(elem) for elem in seq]
  res.append('#$')
  res.insert(0,'^')
  return ''.join(res)

def manacher(seq):
  T = pre_process(seq)
  P = [0]*len(T)
  c,r = 0,0
  for i in range(1,len(T)):
    i_mirror = 2*c - i
    if r > i:
      P[i] = min(r-i, P[i_mirror])
    else:
      P[i] = 0
    while i+1+P[i] < len(T)-1 and i-1-P[i] >=0 and T[ i+1+P[i] ] == T[ i-1-P[i] ]:
      P[i] += 1
    if i + P[i] > r:
      c = i
      r = i+P[i]
  return max(P)


if __name__ == '__main__':
    s = 'madam'
    print(manacher(s))
    print(max(fastLongestPalindromes(s), key=lambda x: x[0])[1])
    print(max(naiveLongestPalindromes(s), key=lambda x: x[0])[1])
