# -*- coding: utf-8 -*-

# bonus for Python
# from heapq import nsmallest
# nsmallest(n, iterable, key=None)

# all example are compatible with both Python 2.7.X and Python 3.X
from heapq import heappush, heappushpop

# 等价于ksmallest1 = lambda lst, k : sorted(lst)[:k]
def ksmallest1(lst, k):
  """
  code example for section 2.1 solution 1
  see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/02.01.md

  author: jiang
  email:  mail.jiang.cn@gmail.com

  created on 2014-5-25
  """
  return sorted(lst)[:k]


def ksmallest2(lst, k):
  """
  code example for section 2.1 solution 2
  see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/02.01.md

  author: jiang
  email:  mail.jiang.cn@gmail.com

  created on 2014-5-25
  """
  result = lst[:k]
  kmax = max(result)
  for elem in lst[k+1:]:
    if elem < kmax:
      result.remove(kmax)
      result.append(elem)
      kmax = max(result)
  return result


def ksmallest3(lst, k):
  """
  code example for section 2.1 solution 3
  see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/02.01.md

  modified by jiang
  email   mail.jaing.cn@gmail.com

  modified on 2014-5-24
  """
  heap = []
  # 需要map是因为标准库中实现的是最小堆
  tmp = map(lambda x: -x, lst)
  for elem in tmp[:k]:
    heappush(heap, elem)
  for elem in tmp[k:]:
    heappushpop(heap, elem)
  return map(lambda x: -x, heap)


if __name__ == "__main__":
    lst = [1, 9, 2, 4, 7, 6, 3]
    k = 3
    print(ksmallest1(lst,k))
    print(ksmallest2(lst,k))
    print(ksmallest3(lst, k))

