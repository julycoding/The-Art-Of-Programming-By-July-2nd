/**
 * Copyright (c) 2014 The TAOPP book Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found 
 * in the LICENSE file.
 * 
 * 	Filename:	SpiralMatrix.c
 * 	Brief		打印顺时针螺旋数组，螺旋方向为从给定方阵左上角开始，右->下->左->上的次序	
 * 	Version:	0.1
 * 	Created:	Fri Mar 21 16:22:26 2014
 * 	Author(s):	Liang Wang<fairywell28@gmail.com>
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 顺时针打印螺旋数组
 *        采用模拟的方法，模拟数组的打印过程，顺时针螺旋输出1～n*n的数值
 * @notice 为方便逻辑理解，数组多申请了一行和一列，便于下标从1开始计算
 * @param n 螺旋数组的行（列）数
 */
void PrintSpiralMatrix(int n)
{
    if (n > 0) {
        int i = 0, j = 0;
        // 正在模拟的当前待填入数值、当前行、当前列
        int curNum = 0, curRow = 0, curCol = 0;
        
        // 为矩阵动态分配空间
        // 如果仅仅是打印，可以不用分配，此处仅为演示
        int **matrix = (int **) malloc((n+1) * sizeof(int *));
        if (NULL == matrix) {
            fprintf(stderr, "malloc failed: out of memory\n");
            exit(-1);
        }

        for (i = 0; i <= n; i++) {
            matrix[i] = (int *) malloc((n+1) * sizeof(int));
            if (NULL == matrix[i]) {
                fprintf(stderr, "malloc failed: out of memory\n");
                exit(-1);
            }
        } 

        curNum = 1;
        // 需要转n/2圈
        for (i = 1; i <= n/2; i++) {
            // 顺序填写第curRow行
            curRow = i;
            for (curCol = i; curCol <= n-i; curCol++) {
                matrix[curRow][curCol] = curNum++;
            }

            // 顺序填写第curCol列
            curCol = n + 1 - i;
            for (curRow = i; curRow <= n-i; curRow++) {
                matrix[curRow][curCol] = curNum++;
            }

            // 逆序填写第curRow行
            curRow = n + 1 - i;
            for (curCol = n+1-i; curCol >= i+1; curCol--) {
                matrix[curRow][curCol] = curNum++;
            }

            // 逆序填写第curCol列
            curCol = i;
            for (curRow = n+1-i; curRow >= i+1; curRow--) {
                matrix[curRow][curCol] = curNum++;
            }
        } // end for
    
        // 如果方阵的阶为奇数，填入中心数
        if (n % 2 == 1) {
            matrix[n/2+1][n/2+1] = curNum; 
        }
        
        // 打印螺旋数组
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                printf("%4d", matrix[i][j]);
            }
            printf("\n");
        }

        // 不要忘记释放malloc的内存
        // 并请注意释放方法
        for (i = 0; i <= n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

int main(void)
{
    printf("-==- test for n=-1 -==-\n");
    PrintSpiralMatrix(-1);
    printf("\n");

    printf("-==- test for n=0 -==-\n");
    PrintSpiralMatrix(0);
    printf("\n");

    printf("-==- test for n=1 -==-\n");
    PrintSpiralMatrix(1);
    printf("\n");

    printf("-==- test for n=2 -==-\n");
    PrintSpiralMatrix(2);
    printf("\n");

    printf("-==- test for n=3 -==-\n");
    PrintSpiralMatrix(3);
    printf("\n");

    printf("-==- test for n=4 -==-\n");
    PrintSpiralMatrix(4);
    printf("\n");

    printf("-==- test for n=5 -==-\n");
    PrintSpiralMatrix(5);
    printf("\n");

    return 0;
}
