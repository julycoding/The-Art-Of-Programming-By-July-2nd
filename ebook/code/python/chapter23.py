# -*- coding:utf-8 -*-
def young_matrix_1(matrix, key):
    if len(matrix) == 0 or len(matrix[0]) == 0:
        return False
    if key < matrix[0][0] or key > matrix[-1][-1]:
        return False
    if key == matrix[0][0] or key == matrix[-1][-1]:
        return True
    w, h = len(matrix), len(matrix[0])
    up = matrix[0:w / 2]
    down = matrix[w / 2:]
    leftup = [i[0:h / 2] for i in up]
    rightup = [i[h / 2:] for i in up]
    leftdown = [i[0:h / 2] for i in down]
    rightdown = [i[h / 2:] for i in down]
    bound0 = leftup[-1][-1]
    bound1 = rightdown[0][0]
    ret = young_matrix_1(rightup, key) or young_matrix_1(leftdown, key)
    if key <= bound0:
        return young_matrix_1(leftup, key) or ret
    elif key > bound0 and key < bound1:
        return ret
    else:  # key >= bound1
        return young_matrix_1(rightdown, key) or ret


def young_matrix(matrix, key):
    # 第二种方法

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
    print young_matrix_1([], 1)
    print young_matrix_1([[]], 1)
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    for i in matrix:
        for j in i:
            if young_matrix_1(matrix, j) == False:
                print j
    print "test over"
