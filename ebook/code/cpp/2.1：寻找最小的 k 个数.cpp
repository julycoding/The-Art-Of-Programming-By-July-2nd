#include <iostream>

using namespace std;

//获取父节点指针
int GetParent(int* pArray, int* pLast)
{
  if(pLast >= pArray)
        return (pLast - pArray + 1) / 2 - 1;
    else
        return -1;
}

//获取左孩子节点指针
int GetLeft(int* pArray, int* pLast)
{
    if(pLast >= pArray)
        return (pLast - pArray + 1) * 2 - 1;
    else
        return -1;
}

//获取右孩子节点指针
int GetRight(int* pArray, int* pLast)
{
    if(pLast >= pArray)
        return (pLast - pArray + 1) * 2;
    else
        return -1;
}

//交换两个元素的值
void Swap(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

//最大化堆过程，保持最大堆性质，即父节点元素值大于等于其子孙节点元素
void MaxHeapify(int* pArray, const int nLength, const int nI)
{
    if((nI < 0) || (pArray == NULL) || (nI > nLength))
    {
        return;
    }

    int nLeft = GetLeft(pArray, pArray+nI);         //获取当前节点的左儿子索引
    int nRight = GetRight(pArray, pArray+nI);       //获取当前节点的右儿子索引
    int* pLargest = NULL;                           //初始化记录最大值的指针

  //若当前元素小于左儿子，则对最大值指针赋值为左儿子指针
    if((nLeft < nLength) && (*(pArray + nI) < *(pArray + nLeft)))
    {
        pLargest = pArray + nLeft;
    }
    else
    {
        pLargest = pArray + nI;
    }

  //若右儿子元素大于最大值元素，则对最大值指针赋值
    if((nRight < nLength) && (*(pLargest) < *(pArray + nRight)))
    {
        pLargest = pArray + nRight;
    }

  //当前元素指针不为最大值，则交换最大值与当前元素值
    if(pLargest != (pArray + nI))
    {
        Swap(pLargest, (pArray + nI));
        {
      //对交换后后的子堆递归进行堆的最大化过程
            MaxHeapify(pArray, nLength, pLargest - pArray);
        }
    }
}

//建立最大堆函数
int BuildMaxHeap(int* pArray, int* pLast)
{
    if((pArray == NULL) || (pLast == NULL))
    {
        return -1;
    }

    int nLength = pLast - pArray + 1;   //获取当前堆数组长度
    int nMid = nLength / 2;

    //对数组的前半数据进行堆最大化过程，因为后半部分数据为叶子节点数据，已经保持了最大堆性质
    for(int i = nMid ; i >= 0; i--)
    {
        MaxHeapify(pArray, nLength, i);
    }
    return 0;
}

//寻找数组中最小的k个数，考虑到对空间的有效利用，这里数组pArray的前k项即为最小的k个数，函数正确返回0，错误返回-1
int FindMinimumK(int* pArray, int nLength, int k)
{
    int nIndex = 0;

    if((pArray == NULL) || (nLength <= 0) || (k <= 0))
        return -1;

    BuildMaxHeap(pArray, pArray + k - 1);

    for(nIndex = k; nIndex < nLength; nIndex++)
    {
        if(pArray[0] > pArray[nIndex])
        {
            Swap(&pArray[0], &pArray[nIndex]);
            MaxHeapify(pArray, k, 0);
        }
    }
    return 0;
}

int main()
{
    int Array[] = {9, 8, 6, 4, 1, 2, 3};
    int k = 3;
    int i = 0;
    FindMinimumK(Array, sizeof(Array) / sizeof(int), k);
    cout << "The " << k << " minimum numbers in Array are:" << endl;
    for(i = 0; i < k; i++)
        cout << Array[i] << " ";
    cout << endl;
    return 0;
}
