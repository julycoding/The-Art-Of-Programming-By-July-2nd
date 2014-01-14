# -*- coding:utf-8 -*-


def young_matrix(matrix, key):
    #第二种方法

    if not matrix or not matrix[0]:
        return False

    m, n = len(matrix), len(matrix[0])
    i, j = 0, n - 1
    while (i < m and j >= 0):
        value = matrix[i][j]
        if key > value:
            i += 1
        elif key < value:
            j -= 1
        else:
            return True


if __name__ == '__main__':
    print young_matrix([], 1)
    print young_matrix([[]], 1)
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    print young_matrix(matrix, 11)
