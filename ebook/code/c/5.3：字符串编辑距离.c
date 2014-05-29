// 5.3 字符串编辑距离.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

//编辑距离
//设每个字符串长度不超过 30

//存储子问题的解 i,j表示X，Y长度
//dp[i][j]表示X[0-i)与Y[0-j)的编辑距离

int dp[31][31];
char X[31];
char Y[31];

//dp[i][j]表示X[0-i)与Y[0-j)的编辑距离
int editDistance(char *pStringX, char *pStringY)
{
	int xLength = strlen(pStringX);
	int yLength = strlen(pStringY);
	int i, j;
	//边界dp[i][0] = i，dp[0][j] = j  
	for (i = 1; i <= xLength; ++i)
	{
		dp[i][0] = i;
	}
	for (j = 1; j <= yLength; ++j)
	{
		dp[0][j] = j;
	}
	for (i = 1; i <= xLength; ++i)
	{
		for (j = 1; j <= yLength; ++j)
		{
			if (pStringX[i - 1] == pStringY[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[xLength][yLength];
}

int main()
{
	cin.getline(X, 30);
	cin.getline(Y, 30);

	printf("%d\n", editDistance(X, Y));
	return 0;
}
