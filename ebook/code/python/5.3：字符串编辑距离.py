#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
最小编辑距离
"""
def Edit_Distance(src, tar):
    srcLength = len(src)
    tarLength = len(tar)
    matrix = [[i+j for j in range(tarLength + 1)] for i in range(srcLength + 1)]
    for i in range(1,srcLength+1):
        matrix[i][0] = i
    for j in range(1,tarLength+1):
        matrix[0][j] = j
    for i in range(1,srcLength+1):
        for j in range(1,tarLength+1):
            if src[i-1] == tar[j-1]:
                matrix[i][j] = matrix[i-1][j-1]
            else:
                matrix[i][j] =min(matrix[i-1][j-1] +1, 1+ min(matrix[i-1][j], matrix[i][j-1]))
    for i in matrix:
        print(i)
    print(matrix[srcLength][tarLength])
    return matrix[srcLength][tarLength]

if __name__ == "__main__":
    # src = 'abddcdefdgbd22svb'
    # tar = 'bcdefg34rdyvdfsd'
    # src = 'ofailing'
    # tar = 'osailn'
    src = "string"
    tar = "story"
    Edit_Distance(src, tar)
