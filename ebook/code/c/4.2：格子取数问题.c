//解法一
//copyright@西芹_new 2013
#include "stdafx.h"
#include <iostream>
using namespace std;

#define N 5
int map[5][5] =
{
	{2, 0, 8, 0, 2},
	{0, 0, 0, 0, 0},
	{0, 3, 2, 0, 0},
	{0, 0, 0, 0, 0},
	{2, 0, 8, 0, 2}
};
int sumMax = 0;
int p1x = 0;
int p1y = 0;
int p2x = 0;
int p2y = 0;
int curMax = 0;

void dfs( int index)
{
	if ( index == 2 * N - 2)
	{
		if ( curMax > sumMax)
			sumMax = curMax;
		return;
	}

	if ( !(p1x == 0 && p1y == 0) && !(p2x == N - 1 && p2y == N - 1))
	{
		if ( p1x >= p2x && p1y >= p2y )
			return;
	}

	//right right
	if ( p1x + 1 < N && p2x + 1 < N )
	{
		p1x++;
		p2x++;
		int sum = map[p1x][p1y] + map[p2x][p2y];
		curMax += sum;
		dfs(index + 1);
		curMax -= sum;
		p1x--;
		p2x--;
	}

	//down down
	if ( p1y + 1 < N && p2y + 1 < N )
	{
		p1y++;
		p2y++;
		int sum = map[p1x][p1y] + map[p2x][p2y];
		curMax += sum;
		dfs(index + 1);
		curMax -= sum;
		p1y--;
		p2y--;
	}

	//rd
	if ( p1x + 1 < N && p2y + 1 < N )
	{
		p1x++;
		p2y++;
		int sum = map[p1x][p1y] + map[p2x][p2y];
		curMax += sum;
		dfs(index + 1);
		curMax -= sum;
		p1x--;
		p2y--;
	}

	//dr
	if ( p1y + 1 < N && p2x + 1 < N )
	{
		p1y++;
		p2x++;
		int sum = map[p1x][p1y] + map[p2x][p2y];
		curMax += sum;
		dfs(index + 1);
		curMax -= sum;
		p1y--;
		p2x--;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	curMax = map[0][0];
	dfs(0);
	cout << sumMax - map[N - 1][N - 1] << endl;
	return 0;
}


//解法二
//2.2、DP方法实现
//copyright@caopengcs 2013
const int N = 202;
const int inf = 1000000000;  //无穷大
int dp[N * 2][N][N];
bool isValid(int step, int x1, int x2, int n) //判断状态是否合法
{
	int y1 = step - x1, y2 = step - x2;
	return ((x1 >= 0) && (x1 < n) && (x2 >= 0) && (x2 < n) && (y1 >= 0) && (y1 < n) && (y2 >= 0) && (y2 < n));
}

int getValue(int step, int x1, int x2, int n)  //处理越界 不存在的位置 给负无穷的值
{
	return isValid(step, x1, x2, n) ? dp[step][x1][x2] : (-inf);
}

//状态表示dp[step][i][j] 并且i <= j, 第step步  两个人分别在第i行和第j行的最大得分 时间复杂度O(n^3) 空间复杂度O(n^3)
int getAnswer(int a[N][N], int n)
{
	int P = n * 2 - 2; //最终的步数
	int i, j, step;

	//不能到达的位置 设置为负无穷大
	for (i = 0; i < n; ++i)
	{
		for (j = i; j < n; ++j)
		{
			dp[0][i][j] = -inf;
		}
	}
	dp[0][0][0] = a[0][0];

	for (step = 1; step <= P; ++step)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = i; j < n; ++j)
			{
				dp[step][i][j] = -inf;
				if (!isValid(step, i, j, n))   //非法位置
				{
					continue;
				}
				//对于合法的位置进行dp
				if (i != j)
				{
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i - 1, j - 1, n));
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i - 1, j, n));
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i, j - 1, n));
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i, j, n));
					dp[step][i][j] += a[i][step - i] + a[j][step - j];  //不在同一个格子，加两个数
				}
				else
				{
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i - 1, j - 1, n));
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i - 1, j,  n));
					dp[step][i][j] = max(dp[step][i][j], getValue(step - 1, i, j,  n));
					dp[step][i][j] += a[i][step - i]; // 在同一个格子里，只能加一次
				}
			}
		}
	}
	return dp[P][n - 1][n - 1];
}

//2.3、DP实现优化版
//copyright@caopengcs 8/24/2013
int dp[2][N][N];

bool isValid(int step, int x1, int x2, int n) //判断状态是否合法
{
	int y1 = step - x1, y2 = step - x2;
	return ((x1 >= 0) && (x1 < n) && (x2 >= 0) && (x2 < n) && (y1 >= 0) && (y1 < n) && (y2 >= 0) && (y2 < n));
}

int getValue(int step, int x1, int x2, int n)  //处理越界 不存在的位置 给负无穷的值
{
	return isValid(step, x1, x2, n) ? dp[step % 2][x1][x2] : (-inf);
}

//状态表示dp[step][i][j] 并且i <= j, 第step步  两个人分别在第i行和第j行的最大得分 时间复杂度O(n^3) 使用滚动数组 空间复杂度O(n^2)
int getAnswer(int a[N][N], int n)
{
	int P = n * 2 - 2; //最终的步数
	int i, j, step, s;

	//不能到达的位置 设置为负无穷大
	for (i = 0; i < n; ++i)
	{
		for (j = i; j < n; ++j)
		{
			dp[0][i][j] = -inf;
		}
	}
	dp[0][0][0] = a[0][0];

	for (step = 1; step <= P; ++step)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = i; j < n; ++j)
			{
				dp[step][i][j] = -inf;
				if (!isValid(step, i, j, n))   //非法位置
				{
					continue;
				}
				s = step % 2;  //状态下表标
				//对于合法的位置进行dp
				if (i != j)
				{
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j - 1, n));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j, n));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i, j - 1, n));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i, j, n));
					dp[s][i][j] += a[i][step - i] + a[j][step - j];  //不在同一个格子，加两个数
				}
				else
				{
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j - 1, n));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j,  n));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i, j,  n));
					dp[s][i][j] += a[i][step - i]; // 在同一个格子里，只能加一次
				}
			}
		}
	}
	return dp[P % 2][n - 1][n - 1];
}
