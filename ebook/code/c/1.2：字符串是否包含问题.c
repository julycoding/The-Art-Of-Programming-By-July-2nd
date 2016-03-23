/*
 * Zaks Wang
 * ultimate010@gmail.com
 * ultimate010.tk
 * 2014-1-2
 */
//判断a字符串是否包含b字符串的字母,假定都没有重复字符出现
#include <stdio.h>
#include <string.h>
#define bool    _Bool
#define TRUE    1
#define false   0

//冒泡法
int partion1(char * arr, int start, int end)
{
    char tmpChar;
    int i;
    while (*(arr + start) <= *(arr + end) && start < end)
    {
        start++; //start 指向第一个大的数据
    }
    if (start == end)
    {
        return start; //已经有序
    }
    for (i = start + 1; i < end; i++)
    {
        if (*(arr + i) < * (arr + end)) //交换
        {
            tmpChar = *(arr + start);
            *(arr + start) = *(arr + i);
            *(arr + i) = tmpChar;
            start++;
        }
    }
    tmpChar = *(arr + start);
    *(arr + start) = *(arr + i);
    *(arr + i) = tmpChar;
    return start;
}

//挖坑法
int partion(char * arr, int start, int end)
{
    char tmpChar = *(arr + start);
    while (start < end)
    {
        while (*(arr + end) >= tmpChar && end > start)
        {
            end--;
        }
        if (start < end)
        {
            *(arr + start) = *(arr + end); //小的往左走
            start++;
        }
        else
        {
            break;
        }
        while (*(arr + start) <= tmpChar && end > start)
        {
            start++;
        }
        if (start < end)
        {
            *(arr + end) = *(arr + start);
            end--;
        }
        else
        {
            break;
        }
    }
    *(arr + start) = tmpChar;
    return start;
}
//快排
void quickSort(char * arr, int start, int end)
{
    if (start < end)
    {
        int mid = partion1(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}
//计数排序,只针对大写字母
void countSort(char * oldArr, char * newArr)
{
    int count[26] = {0};
    int i;
    int lenOld = strlen(oldArr);
    memset(newArr, 0, lenOld); //clear
    int pos;
    for (i = 0; i < lenOld; i++)
    {
        pos = *(oldArr + i) - 'A';
        count[pos]++;
    }
    for (i = 0; i < 25; i++)
    {
        count[i + 1] += count[i];
    }
    for (i = 0; i < lenOld; i++)
    {
        pos = count[*(oldArr + i) - 'A'];
        while (newArr[pos - 1] != 0)
        {
            pos++;
        }
        newArr[pos - 1] = *(oldArr + i);
    }
}

//暴力求解法
bool contain1(char * stra, char * strb)
{
    int lena = strlen(stra);
    int lenb = strlen(strb);
    int i, j;
    for (i = 0; i < lenb; i++)
    {
        for (j = 0; j < lena; j++)
        {
            if (*(stra + j) == *(strb + i))
            {
                break;
            }
        }
        if (j == lena)
        {
            return false;
        }
    }
    return TRUE;
}

//排序比较法
bool contain2(char * stra, char * strb)
{
    char tmpA[100] = {0};
    char tmpB[100] = {0};
    /*    use quickSort
      sprintf(tmpA,"%s",stra);
      sprintf(tmpB,"%s",strb);
      quickSort(tmpA,0,strlen(tmpA) - 1);
      quickSort(tmpB,0,strlen(tmpB) - 1);
      */
    countSort(stra, tmpA);
    countSort(strb, tmpB);
    //printf("After sort:\n%s\n%s\n",tmpA,tmpB);
    int lena = strlen(tmpA);
    int lenb = strlen(tmpB);
    int i, j;
    for (i = 0, j = 0; j < lena && i < lenb; j++)
    {
        if (tmpA[j] == tmpB[i])
        {
            i++;
        }
        else if (tmpA[j] > tmpB[i])
        {
            return false;
        }
    }
    if (i == lenb)
    {
        return TRUE;
    }
    else
    {
        return false;
    }
}
//hash测试法
bool contain3(char * stra, char * strb)
{
    int hashTable[26] = {0};
    int i, count = 0;
    int lena = strlen(stra);
    int lenb = strlen(strb);
    for (i = 0; i < lenb; i++)
    {
        hashTable[*(strb + i) - 'A'] = 1;
        count++;
    }
    for (i = 0; i < lena && count > 0; i++)
    {
        if (hashTable[*(stra + i) - 'A']) //no need to make the hashTable to be 0
        {
            count--;
        }
    }
    if (count == 0)
    {
        return TRUE;
    }
    else
    {
        return false;
    }
}
//bit法,区分大小写
bool contain4(char * stra, char * strb)
{
    unsigned long long bitA = 0, bitB = 0; //必须用long long,64位才不会溢出
    while (*stra)
    {
        bitA |= (unsigned long long)(1l << (*stra++ & 0x3f)); //取8位中的后6位,a:97:01100001b A:65:01000001b 0x3f:00111111b;
    }
    while (*strb)
    {
        bitB |= (unsigned long long)(1l << (*strb++ & 0x3f));
    }
    return !((bitA ^ bitB) & bitB); //bitA ^ bitB 之后的结果,对于bitB中非0位,为1的话表示A中与B中某位不同,所以不包含
}
//素数方法,不能处理大量字符串,因为使用的unsigned long long溢出
bool contain5(char * stra, char * strb)
{
    int primeNumber[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
                           61, 67, 71, 73, 79, 83, 89, 97, 101
                          };
    unsigned long long bigNumber = 1; //too small for use.
    while (*stra)
    {
        bigNumber *= primeNumber[*stra - 'A'];
        stra++;
    }
    while (*strb)
    {
        if (0 != (bigNumber % primeNumber[*strb - 'A']))
        {
            break;
        }
        strb++;
    }
    if (*strb)
    {
        return false;
    }
    else
    {
        return TRUE;
    }
}


int main()
{
    char stra[50];
    char strb[50];
    char strc[50];
    sprintf(stra, "ABCDEFGHLMNOPQRS");
    sprintf(strb, "DCGSRQPO");
    sprintf(strc, "DCGSRQPZ");

    if (contain1(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain1(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain2(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain2(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain3(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain3(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain4(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain4(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain4("a", "A"))
        printf("a contain A in bit hack method\n");

    /*
     if(contain5("Ab","b")){
     printf("%s contain %s\n",stra,strb);
     }else{
     printf("%s not contain %s\n",stra,strb);
     }
     printf("\n");
     */
    return 0;
}

