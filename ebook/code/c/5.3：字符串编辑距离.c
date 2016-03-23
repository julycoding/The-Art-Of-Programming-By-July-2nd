// 5.3 字符串编辑距离.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

//编辑距离
//设每个字符串长度不超过 2000

//存储子问题的解 i,j表示source，target长度
//dp[i][j]表示source[0-i)与target[0-j)的编辑距离

int dp[2000][2000];
char source[2000];
char target[2000];

//dp[i][j]表示source[0-i)与target[0-j)的编辑距离
int editDistance(char *pSource, char *pTarget)
{
	int srcLength = strlen(pSource);
	int targetLength = strlen(pTarget);
	int i, j;
	//边界dp[i][0] = i，dp[0][j] = j  
	for (i = 1; i <= srcLength; ++i)
	{
		dp[i][0] = i;
	}
	for (j = 1; j <= targetLength; ++j)
	{
		dp[0][j] = j;
	}
	for (i = 1; i <= srcLength; ++i)
	{
		for (j = 1; j <= targetLength; ++j)
		{
			if (pSource[i - 1] == pTarget[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[srcLength][targetLength];
}

int main()
{
	cout << "hello July" << endl;
	cin.getline(source, 30);
	cin.getline(target, 30);

	printf("%d\n", editDistance(source, target));
	return 0;
}
