// 4.3 出现次数超过一半.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
using namespace std;

//a代表数组，length代表数组长度
int FindOneNumber(int* a, int length)
{
	int candidate = a[0];
	int nTimes, i;
	for (i = nTimes = 0; i < length; i++)
	{
		if (candidate == a[i])
			nTimes++;
		else 
			nTimes--;
		if (nTimes == 0)
		{
			candidate = a[i];
			nTimes = 1;
		}
	}
	return candidate;
}

int main()
{
	int a[10] = { 1, 2, 3, 4, 6, 6, 6, 6, 6 };
	int* n = a;
	cout << FindOneNumber(a, 9) << endl;
	return 0;
}
