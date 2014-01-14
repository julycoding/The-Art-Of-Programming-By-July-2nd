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


def compare_3(long_string, short_string):
    """
    code example for section 1.3

    see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/02.0.md#13-onm%E7%9A%84%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F%E6%96%B9%E6%B3%95
    """

    def count_sort(src):
        #
        dst = [''] * len(src)

        # 辅助计数数组
        tmp = [0] * 26

        # help[index]存放了等于index + 'A'的元素个数
        for char in src:
            tmp[ord(char) - ord('A')] += 1

        # 求出每个元素对应的最终位置
        for i in xrange(1, len(tmp)):
            tmp[i] = tmp[i] + tmp[i - 1]

        # 把每个元素放到其对应的最终位置
        for i in xrange(len(src) - 1, -1, -1):
            c = src[i]
            index = ord(c) - ord('A')
            dst[tmp[index] - 1] = c
            tmp[index] -= 1

        return ''.join(dst)

    sorted_long_string = count_sort(long_string)
    sorted_short_string = count_sort(short_string)

    pos_long = 0
    pos_short = 0
    while (pos_short < len(sorted_short_string) and pos_long < len(sorted_long_string)):
        # 如果pos_long递增直到long_str[pos_long] >= short_str[pos_short]
        while (sorted_long_string[pos_long] < sorted_short_string[pos_short] and pos_long < len(
                sorted_long_string) - 1):
            pos_long += 1

        if (sorted_long_string[pos_long] != sorted_short_string[pos_short]):
            break

        pos_short += 1

    return pos_short == len(sorted_short_string)


def compare_4(long_string, short_string):
    """
    code example for section 2.1

    see https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/02.0.md#21-onm%E7%9A%84hashtable%E7%9A%84%E6%96%B9%E6%B3%95
    """

    # 辅助数组
    hash_tmp = [0] * 26

    # 辅助数组中元素个数
    count = 0

    # 扫描短字符串
    for char in short_string:
        index = ord(char) - ord('A')
        if not hash_tmp[index]:
            hash_tmp[index] += 1
            count += 1

    # 扫描长字符串
    for char in long_string:
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
    long = "ABCDEFGHLMNOPQRS"
    short = "DCGSRQPX"

    print compare_1(long, short)
    print compare_2(long, short)
    print compare_3(long, short)
    # print compare_3('ABCDAK', 'AA')
    print compare_4(long, short)
    print compare_5(long, short)
    print compare_6(long, short)
    print compare_7(long, short)
