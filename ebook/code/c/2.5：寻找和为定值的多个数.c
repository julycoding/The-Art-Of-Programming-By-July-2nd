//解法一
//copyright@ July && yansha
//updated@ 2014 July
#include<list>
#include<iostream>
using namespace std;

list<int>list1;
void SumOfkNumber(int sum, int n)
{
	// 递归出口
	if (n <= 0 || sum <= 0)
		return;

	// 输出找到的结果
	if (sum == n)
	{
		// 反转list
		list1.reverse();
		for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
			cout << *iter << " + ";
		cout << n << endl;
	}

	list1.push_front(n);      //典型的01背包问题
	SumOfkNumber(sum - n, n - 1);   //放n，n-1个数填满sum-n
	list1.pop_front();
	SumOfkNumber(sum, n - 1);     //不放n，n-1个数填满sum
}

int main()
{
	int sum, n;
	cout << "请输入你要等于多少的数值sum:" << endl;
	cin >> sum;
	cout << "请输入你要从1.....n数列中取值的n：" << endl;
	cin >> n;
	cout << "所有可能的序列，如下：" << endl;
	SumOfkNumber(sum, n);
	system("pause");
	return 0;
}

//解法二
//copyright@ 2011 zhouzhenren
//updated@2014 July
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
using namespace std;

/**
* 输入t， r， 尝试Wk
*/
void SumOfkNumber(int t, int k, int r, int& M, bool& flag, bool* X)
{
	X[k] = true;   // 选第k个数
	if (t + k == M) // 若找到一个和为M，则设置解向量的标志位，输出解
	{
		flag = true;
		for (int i = 1; i <= k; ++i)
		{
			if (X[i] == 1)
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	else
	{   // 若第k+1个数满足条件，则递归左子树
		if (t + k + (k + 1) <= M)
		{
			SumOfkNumber(t + k, k + 1, r - k, M, flag, X);
		}
		// 若不选第k个数，选第k+1个数满足条件，则递归右子树
		if ((t + r - k >= M) && (t + (k + 1) <= M))
		{
			X[k] = false;
			SumOfkNumber(t, k + 1, r - k, M, flag, X);
		}
	}
}

void search(int& N, int& M)
{
	// 初始化解空间
	bool* X = (bool*)malloc(sizeof(bool)* (N + 1));
	memset(X, false, sizeof(bool)* (N + 1));
	int sum = (N + 1) * N * 0.5f;
	if (1 > M || sum < M) // 预先排除无解情况
	{
		printf("not found\n");
		return;
	}
	bool f = false;
	SumOfkNumber(0, 1, sum, M, f, X);
	if (!f)
	{
		printf("not found\n");
	}
	free(X);
}

int main()
{
	int sum, n;
	cout << "请输入你要等于多少的数值sum:" << endl;
	cin >> sum;
	cout << "请输入你要从1.....n数列中取值的n：" << endl;
	cin >> n;
	cout << "所有可能的序列，如下：" << endl;
	search(sum, n);
	system("pause");
	return 0;
}
