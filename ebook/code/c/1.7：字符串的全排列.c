//解法一、代码①
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

void calcAllPermutation(char* perm, int from, int to)
{
	if (to <= 1)
	{
		return;
	}

	if (from == to)
	{
		for (int i = 0; i <= to; i++)
			cout << perm[i];
		cout << endl;
	}
	else
	{
		for (int j = from; j <= to; j++)
		{
			swap(perm[j], perm[from]);
			calcAllPermutation(perm, from + 1, to);
			swap(perm[j], perm[from]);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[] = "abc";
	cout << a << "所有全排列的结果为：" << endl;
	calcAllPermutation(a, 0, 2);
	system("pause");
	return 0;
}


//解法二 代码一
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

void calcAllPermutation(char* perm, int num)
{
	if (num < 1)
		return;

	for (int i = 0; i < num; i++)
	{
		cout << perm[i];
	}
	cout << endl;

	while (true)
	{
		int i;
		for (i = num - 2; i >= 0; --i)
		{
			if (perm[i] < perm[i + 1])
				break;
		}
		if (i < 0)
		{
			break;  // 已经找到所有排列
		}
		int k;
		for (k = num - 1; k > i; --k)
		{
			if (perm[k] > perm[i])
				break;
		}
		swap(perm[i], perm[k]);
		//reverse 左闭右开
		reverse(perm + i + 1, perm + num);
		for (int i = 0; i < num; i++)
		{
			cout <<perm[i];
		}
		cout << endl;
	}
}

int main()
{
	char a[] = "123";
	calcAllPermutation(a, 3);
	return 0;
}



//解法二 代码二
// 1.7 字符串的全排列.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

bool CalcAllPermutation(char* perm, int num){
	int i;

	//①找到排列中最后（最右）一个升序的首位位置i，x = ai
	for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i){
		;
	}
	// 已经找到所有排列
	if (i < 0){
		return false;
	}

	int k;
	//②找到排列中第i位右边最后一个比ai 大的位置j，y = aj
	for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k){
		;
	}

	//③交换x，y
	swap(perm[i], perm[k]);
	//④把第(i+ 1)位到最后的部分翻转
	reverse(perm + i + 1, perm + num);
	return true;
}

int main()
{
	char a[] = "123";
	do{
		for (int i = 0; i < 3; ++i)
			cout << a[i];
		cout << endl;
	} while (CalcAllPermutation(a, 3));
	return 0;
}


//类似问题
//假设str已经有序，from 一直很安静  
void perm(char *str, int size, int resPos)  
{  
	if(resPos == size)  
		print(result);  
	else  
	{  
		for(int i = 0; i < size; ++i)  
		{  
			result[resPos] = str[i];  
			perm(str, size, resPos + 1);  
		}  
	}  
}  
