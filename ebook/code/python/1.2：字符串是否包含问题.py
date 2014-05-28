# coding=utf-8
def compare_1(long_string, short_string):
    """
    code example for section 1.1

    see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/02.0.md#11-onm%E7%9A%84%E8%BD%AE%E8%AF%A2%E6%96%B9%E6%B3%95
    """
    i, j = 0, 0
    n, m = len(long_string), len(short_string)
    while (i < m):
        while (j < n):  # O(n*m)
            if long_string[j] == short_string[i]:  # 一一比较
                break
            else:
                j += 1

        if j == n:
            return False
        else:
            i += 1
            j = 0

    return True


def compare_2(long_string, short_string):
    """
    code example for section 1.2

    see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/02.0.md#12-omlogmonlognomn%E7%9A%84%E6%8E%92%E5%BA%8F%E6%96%B9%E6%B3%95
    """
    sorted_long = sorted(long_string)  # 快排借用Python内置函数
    sorted_short = sorted(short_string)  # 快排借用Python内置函数

    i, j = 0, 0
    n, m = len(sorted_long), len(sorted_short)

    while (i < n and j < m):
        while (sorted_long[i] < sorted_short[j] and i < n - 1):
            i += 1

        if sorted_long[i] != sorted_short[j]:
            break

        j += 1

    return j == m

def string_contain3(long_str, short_str):
  """
  code example for section 1.2 solution 3
  see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.02.md

  author: jiang
  email:  mail.jiang.cn@gmail.com

  created on 2014-5-24

  work with both Python 2.7.X and Python 3.X
  """
  have = [0] * 26
  for char in long_str:
    have[ord(char) - ord('A')] += 1
  for char in short_str:
    if have[ord(char) - ord('A')] == 0:
      return False
  return True


def string_contain4(long_str, short_str):
    """
    code example for section 1.2 solution 4
    see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.02.md 

    modified by jiang
    email   mail.jiang.cn@gmail.com

    modified on 2014-5-25

    work with both Python 2.7.X and Python 3.X
    """

    # 辅助数组
    hash_tmp = [0] * 26

    # 辅助数组中元素个数
    count = 0

    # 先扫描短字符串（提升第三种解法时间效率的关键点一）
    for char in short_str:
      index = ord(char) - ord('A')
      if hash_tmp[index] == 0:    # 显式标明条件
         hash_tmp[index] += 1
         count += 1

    # 扫描长字符串
    for char in long_str:
      # 提升第三种解法时间效率的关键点二，没有这步则不能提高效率
      if count > 0:
        index = ord(char) - ord('A')
        if hash_tmp[index] == 1:
          hash_tmp[index] -= 1
          count -= 1

    return count == 0


def compare_5(long_string, short_string):
    """
    code example for section 2.2

    see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/02.0.md#22onm%E7%9A%84%E6%95%B0%E7%BB%84%E5%AD%98%E5%82%A8%E6%96%B9%E6%B3%95
    """
    # 辅助数组
    hash_tmp = [False] * 26

    # 扫描短字符串
    for char in short_string:
        index = ord(char) - ord('A')
        if not hash_tmp[index]:
            hash_tmp[index] = True

    # 扫描长字符串
    for char in long_string:
        index = ord(char) - ord('A')
        if hash_tmp[index]:
            hash_tmp[index] = False

    return not hash_tmp.count(True)


def compare_6(long_string, short_string):
    """
    code example for section 3.1

    see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/02.0.md#%E7%AC%AC%E4%B8%89%E8%8A%82-on%E5%88%B0onm%E7%9A%84%E7%B4%A0%E6%95%B0%E6%96%B9%E6%B3%95
    """
    prime_number = (2, 3, 5, 7,
                    11, 13, 17, 19,
                    23, 29, 31, 37,
                    41, 43, 47, 53,
                    59, 61, 67, 71,
                    73, 79, 83, 89,
                    97, 101)

    product = 1

    for char in long_string:
        index = ord(char) - ord('A')
        product *= prime_number[index]

    for char in short_string:
        index = ord(char) - ord('A')
        if product % prime_number[index]:
            return False

    return True


def compare_7(long_string, short_string):
    return set(short_string) - set(long_string) == set([])


if __name__ == '__main__':
    long_str = "ABCDEFGHLMNOPQRS"
    short_str = "DCGSRQPX"

    print(compare_1(long_str, short_str))
    print(compare_2(long_str, short_str))
    print(string_contain3(long_str,short_str))
    print(string_contain4(long_str, short_str))
    print(compare_5(long_str, short_str))
    print(compare_6(long_str, short_str))
    print(compare_7(long_str, short_str))
