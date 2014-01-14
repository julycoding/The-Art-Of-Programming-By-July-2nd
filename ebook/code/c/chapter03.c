/*
 *  Zaks Wang
 *  ultimate010@gmail.com
 *  ultimate010.tk
 *  2013-1-3
 */
//寻找最大或最小k个数,以及堆排序,利用最小或最大堆实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * 最大堆筛选过程
 * @arr 数组头指针,调整后的指针
 * @len 数组长度,注意最后一位表示方法为*(arr + len),不是*(arr + len -1);
 * @pos 调整位置,1开始
 */
void _adjustForMaxHeap(int * arr, int len, int pos)
{
    int key = *(arr + pos);
    int i, j;
    for (i = pos * 2; i <= len; i *= 2) //找各个儿子
    {
        if (i < len && *(arr + i) < * (arr + i + 1))
        {
            i++; //左右儿子中找最大的
        }
        if (key >= *(arr + i))
        {
            break; //调整完成,因为当前节点比所有儿子都大
        }
        *(arr + pos) = *(arr + i);
        pos = i; //此时pos指针移动到,新的放key位置,就是儿子的位置
    }
    *(arr + pos) = key; //仅仅最后插入key
}

/*
 * 最小堆筛选过程
 * @arr 数组头指针,调整后的指针
 * @len 数组长度,注意最后一位表示方法为*(arr + len),不是*(arr + len -1);
 * @pos 调整位置,1开始
 */
void _adjustForMinHeap(int * arr, int len, int pos)
{
    int key = *(arr + pos);
    int i, j;
    for (i = pos * 2; i <= len; i *= 2) //找各个儿子
    {
        if (i < len && *(arr + i) > *(arr + i + 1))
        {
            i++; //左右儿子中找最小的
        }
        if (key <= *(arr + i))
        {
            break; //调整完成,因为当前节点比所有儿子都大
        }
        *(arr + pos) = *(arr + i);
        pos = i; //此时pos指针移动到,新的放key位置,就是儿子的位置
    }
    *(arr + pos) = key; //仅仅最后插入key
}
/*
 * 建立最大堆
 * @arr 数组头指针
 * @len 数组长度
 */
void buildMaxHeap(int * arr, int len)
{
    int i;
    --arr; //将arr指针前移一位,从0开始转换为1开始
    for (i = (len / 2); i > 0; i--) //len / 2 to 1
    {
        _adjustForMaxHeap(arr, len, i);
    }
}
/*
 * 建立最小堆
 * @arr 数组头指针
 * @len 数组长度
 */
void buildMinHeap(int * arr, int len)
{
    int i;
    --arr; //将arr指针前移一位,从0开始转换为1开始
    for (i = (len / 2); i > 0; i--) //len / 2 to 1
    {
        _adjustForMinHeap(arr, len, i);
    }
}
/*
 *最小K个数
 *@arr 数组头指针
 *@len 数组长度
 *@k k个数
 */
void printMinKNum(int * arr, int len, int k)
{
    int * tmpArr = (int *) malloc(len * sizeof(int));
    memcpy(tmpArr, arr, len);
    buildMaxHeap(arr, k); //建立k个节点的最大堆
    int i;
    for (i = k; i < len; i++)
    {
        if (*(arr + i) < *arr) //当前数据比堆中最大的数据小,那么当前数据应该是K个数之一
        {
            swap(arr, arr + i);
            _adjustForMaxHeap(arr - 1, k, k / 2); //前K个数据重新调整
            //buildMaxHeap(arr,k); //或者重新建堆
        }
    }
    printf("The min k number is:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
    free(tmpArr);
}
/*
 *最大K个数
 *@arr 数组头指针
 *@len 数组长度
 *@k k个数
 */
void printMaxKNum(int * arr, int len, int k)
{
    int * tmpArr = (int *) malloc(len * sizeof(int));
    memcpy(tmpArr, arr, len);
    buildMinHeap(arr, k);
    int i;
    for (i = k; i < len; i++)
    {
        if (*(arr + i) > *arr) //当前数据比堆中最小的数据大,那么当前数据应该是K个数之一
        {
            swap(arr, arr + i);
            //_adjustForMinHeap(arr - 1,k,k / 2);
            buildMinHeap(arr, k);
        }
    }
    printf("The max k number is:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
    free(tmpArr);
}
/*
 * 堆排序,升序
 *@arr 数组头指针
 *@len 数组长度
 */
void heapSortAsc(int * arr, int len)
{
    int i;
    for (i = len; i > 0;) //len to 1
    {
        buildMaxHeap(arr, i);
        swap(arr, arr + --i);
    }
}
/*
 * 堆排序,降序
 *@arr 数组头指针
 *@len 数组长度
 */
void heapSortDsc(int * arr, int len)
{
    int i;
    for (i = len; i > 0;) //len to 1
    {
        buildMinHeap(arr, i);
        swap(arr, arr + --i);
    }
}
int main()
{
    int arr[6] = {1, 234, 12, 132, 12, 321};
    int i = 6;
    printf("The arr is :\n");
    while (i--)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printMinKNum(arr, 6, 3);
    printMaxKNum(arr, 6, 3);

    int sortArr[24] = {0};
    for (i = 0; i < 24; i++)
    {
        sortArr[i]  = i;
    }
    sortArr[20] = 3;
    printf("The sortarr is :\n");
    i = 0;
    while (i < 24)
    {
        printf("%d\t", sortArr[i++]);
    }
    printf("\n");

    heapSortAsc(sortArr, 24);

    printf("After sort,the sortarr is :\n");
    i = 0;
    while (i < 24)
    {
        printf("%d\t", sortArr[i++]);
    }
    printf("\n");

    heapSortDsc(sortArr, 24);

    printf("After sort,the sortarr is :\n");
    i = 0;
    while (i < 24)
    {
        printf("%d\t", sortArr[i++]);
    }
    printf("\n");

    return 0;
}

