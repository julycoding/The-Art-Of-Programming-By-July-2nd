#!/usr/bin/python
# -*- coding:utf-8 -*-

def young_matrix(matrix, key):
    '''第二种方法'''
    if len(matrix) > 0 and len(matrix[0]) > 0:
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
    return False

def main():
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    print young_matrix(matrix, 11)
    return

if __name__ == '__main__':
    main()
