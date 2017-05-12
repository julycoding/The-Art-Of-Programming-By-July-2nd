/*
 * Zaks Wang
 * ultimate010@gmail.com
 * ultimate010.tk
 * 2013-12-31
 */
#include <stdio.h>
#include <string.h>
//字符串旋转问题,例如abcdef 左旋2位 变成 cdefab

//暴力移位法
void leftShift1(char * arr, int n)
{
    size_t tmpLen = strlen(arr);
    char tmpChar;
    int i, j;
    if (n >= 0)
    {
        for (i = 0; i < n; i++)
        {
            tmpChar = *arr;
            for (j = 0; j < tmpLen - 1; j++)
            {
                *(arr + j) = *(arr + j + 1);
            }
            *(arr + tmpLen - 1) = tmpChar;
        }
    }
    else
    {
        for (i = 0; i < -n; i++)
        {
            tmpChar = *(arr + tmpLen - 1);
            for (j = tmpLen - 1; j > 0; j--)
            {
                *(arr + j) = *(arr + j - 1);
            }
            *arr = tmpChar;
        }
    }
}
//指针移位法
void leftShift2(char * arr, int len, int n)
{
    int i;
    size_t tmpLen = len;
    int p0 = 0;
    int p1 = n;
    char tmpChar;
    /*  O(m - n - k)  k is the last section*/
    while (p1 + n - 1 < tmpLen)
    {
        tmpChar = *(arr + p0);
        *(arr + p0) = *(arr + p1);
        *(arr + p1) = tmpChar;
        p0++;
        p1++;
    }
    /*
     *  not good O(k * (n + k)) k = tmpLen - p1
     for(i = 0;i < tmpLen - p1;i++){ //移动后面剩下的
     tmpChar = *(arr + tmpLen - 1);
     for(j = tmpLen - 1;j > p0;j--){
     *(arr + j) = *(arr + j -1);
     }
     *(arr + p0) = tmpChar;
     }
     */
    /* good O(k * n) */
    while (p1 < tmpLen)
    {
        tmpChar = *(arr + p1);
        for (i = p1; i > p0; i--)
        {
            *(arr + i) = *(arr + i - 1);
        }
        *(arr + p0) = tmpChar;
        p0++;
        p1++;
    }
}
//指针移位法,尾部处理用递归
void leftShift3(char * arr, int len, int n)
{
    size_t tmpLen = len;
    int p0 = 0;
    int p1 = n;
    char tmpChar;
    /*  O(m - n - k)  k is the last section*/
    while (p1 + n - 1 < tmpLen)
    {
        tmpChar = *(arr + p0);
        *(arr + p0) = *(arr + p1);
        *(arr + p1) = tmpChar;
        p0++;
        p1++;
    }
    if (p1 < tmpLen)
    {
        leftShift2(arr + p0, len - p0, n);
    }
}
//指针移位法,递归
void leftShift4(char * arr, int len, int n)
{
    size_t tmpLen = len;
    int p0 = 0;
    int p1 = n;
    char tmpChar;
    /*  O(m - n - k)  k is the last section*/
    while (p1 < tmpLen)
    {
        tmpChar = *(arr + p0);
        *(arr + p0) = *(arr + p1);
        *(arr + p1) = tmpChar;
        p0++;
        p1++;
    }
    int i = n - tmpLen % n;
    if (i != 0 && p0 != tmpLen - 1) // p0 can not be the tmpLen - 1
    {
        leftShift4((arr + p0), n, i);
    }
}

void myinvert(char * start, char * end)
{
    char tmpChar;
    while (start < end)
    {
        tmpChar = *start;
        *start = *end;
        *end = tmpChar;
        start++;
        end--;
    }
}

//翻转法
void leftShift5(char * arr, int len, int n)
{
    myinvert(arr, arr + n - 1);
    myinvert(arr + n, arr + len - 1);
    myinvert(arr, arr + len - 1);
}
int gcd(int m, int n)
{
    int r;
    while ((r = m % n))
    {
        m = n;
        n = r;
    }
    return n;
}
//循环移位法
void leftShift6(char * arr, int len, int n)
{
    int group = gcd(len, n);
    char tmpChar;
    int x = len / group;
    int i, j;
    for (i = 0; i < group; i++)
    {
        tmpChar = *(arr + i);
        for (j = 0; j < x - 1; j++)
        {
            *(arr + (i + (j * n)) % len) = *(arr + (i + (j * n) + n) % len);
        }
        *(arr + (i + (j * n)) % len) = tmpChar;
    }
}
int main()
{
    char str[50];
    sprintf(str, "abcdefghijk");
    printf("The origin str is :%s\tlen is :%zu\n", str, strlen(str));
    printf("\n");
    leftShift1(str, 2);
    printf("The leftShift1 str is :%s\n", str);
    leftShift1(str, -2);
    printf("The leftShift1 str is :%s\n", str);
    leftShift1(str, 3);
    printf("The leftShift1 str is :%s\n", str);
    leftShift1(str, strlen(str) - 3);
    printf("The leftShift1 str is :%s\n", str);
    printf("\n");

    leftShift2(str, strlen(str), 3);
    printf("The leftShift2 str is :%s\n", str);
    leftShift2(str, strlen(str), strlen(str) - 3);
    printf("The leftShift2 str is :%s\n", str);
    leftShift2(str + 2, strlen(str) - 2, 2);
    printf("The leftShift2 str is :%s\n", str);
    leftShift2(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift2 str is :%s\n", str);
    printf("\n");


    leftShift3(str, strlen(str), 3);
    printf("The leftShift3 str is :%s\n", str);
    leftShift3(str, strlen(str), strlen(str) - 3);
    printf("The leftShift3 str is :%s\n", str);
    leftShift3(str + 2, strlen(str) - 2, 2);
    printf("The leftShift3 str is :%s\n", str);
    leftShift3(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift3 str is :%s\n", str);
    printf("\n");

    leftShift4(str, strlen(str), 3);
    printf("The leftShift4 str is :%s\n", str);
    leftShift4(str, strlen(str), strlen(str) - 3);
    printf("The leftShift4 str is :%s\n", str);
    leftShift4(str + 2, strlen(str) - 2, 2);
    printf("The leftShift4 str is :%s\n", str);
    leftShift4(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift4 str is :%s\n", str);
    printf("\n");

    leftShift5(str, strlen(str), 3);
    printf("The leftShift5 str is :%s\n", str);
    leftShift5(str, strlen(str), strlen(str) - 3);
    printf("The leftShift5 str is :%s\n", str);
    leftShift5(str + 2, strlen(str) - 2, 2);
    printf("The leftShift5 str is :%s\n", str);
    leftShift5(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift5 str is :%s\n", str);
    printf("\n");

    leftShift6(str, strlen(str), 3);
    printf("The leftShift6 str is :%s\n", str);
    leftShift6(str, strlen(str), strlen(str) - 3);
    printf("The leftShift6 str is :%s\n", str);
    leftShift6(str + 2, strlen(str) - 2, 2);
    printf("The leftShift6 str is :%s\n", str);
    leftShift6(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift6 str is :%s\n", str);
    printf("\n");

    return 0;
}
