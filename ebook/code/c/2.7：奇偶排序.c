// 6.7 奇偶排序.cpp : 定义控制台应用程序的入口点。
//实现一
#include "stdafx.h"
#include <iostream>
using namespace std;

//判断是否为奇数
bool isOddNumber(int data)
{
	return data & 1 == 1;
}

//交换两个元素
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//奇偶互换
void oddEvenSort(int *pData, unsigned int length)
{
	if (pData == NULL || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		//如果pBegin指针指向的是奇数，正常，向后移
		if (isOddNumber(*pBegin))
		{
			pBegin++;
		}
		//如果pEnd指针指向的是偶数，正常，向前移
		else if (!isOddNumber(*pEnd))
		{
			pEnd--;
		}
		else
		{
			//否则都不正常，交换
			swap(*pBegin, *pEnd);
		}
	}
}

int main(int argc, _TCHAR* argv[])
{
	int data[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++)
		cout << data[i] << " ";
	cout << endl;
	oddEvenSort(data, 5);
	for (int i = 0; i < 5; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}



//实现二
// 6.7 奇偶排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//判断是否为奇数
bool isOddNumber(int data)
{
	return data & 1 == 1;
}

//交换两个元素
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//奇偶互换
void oddEvenSort2(int data[], int lo, int hi)
{
	int i = lo - 1;
	for (int j = lo; j < hi; j++)
	{
		//data[j]指向奇数，交换
		if ( isOddNumber(data[j]) )
		{
			i = i + 1;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[hi]);
}

int main(int argc, _TCHAR* argv[])
{
	int data[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		cout << data[i] << " ";
	cout << endl;
	oddEvenSort2(data, 0, 4);
	for (int i = 0; i < 5; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
