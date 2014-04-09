//解法一
// 动态规划：

// f[i,j]表示s[0...i]与t[0...j]的最小编辑距离。
f[i, j] = min { f[i - 1, j] + 1,  f[i, j - 1] + 1,  f[i - 1, j - 1] + (s[i] == t[j] ? 0 : 1) }

// 分别表示：添加1个，删除1个，替换1个（相同就不用替换）。


//解法二
//copyright@ peng_weida
//实现代码如下：
//头文件StrEditDistance.h
#pragma once
#include <string>
class CStrEditDistance
{
public:
	CStrEditDistance(std::string& vStrRow, std::string& vStrColumn);
	~CStrEditDistance(void);
	int  getScore()
	{
		return m_Score;
	}
	int  getEditDis()
	{
		return m_EditDis;
	}
	void setEditDis(int vDis)
	{
		m_EditDis = vDis;
	}
	void setScore(int vScore)
	{
		m_Score = vScore;
	}
private:
	void process(const std::string& vStrRow, const std::string& vStrColumn);
	int getMaxValue(int a, int b, int c)
	{
		if (a < b)
		{
			if (b < c) return c;
			return b;
		}
		else
		{
			if (b > c) return a;
			return a < c ? c : a;
		}
	}
private:
	int   m_EditDis;
	int   m_Score;
};
//源文件StrEditDistance.cpp
#include "StrEditDistance.h"
#include <iostream>
#include <iomanip>
#define MATCH        2
#define MISS_MATCH   -1
#define INSERT       -1
#define DELETE       -1
CStrEditDistance::CStrEditDistance(std::string& vStrRow, std::string& vStrColumn)
{
	process(vStrRow, vStrColumn);
}
CStrEditDistance::~CStrEditDistance(void)
{
}
//FUNCTION:
void CStrEditDistance::process(const std::string& vStrRow, const std::string& vStrColumn)
{
	int editDis = 0;     //编辑距离
	int row = vStrColumn.length();
	int column = vStrRow.length();
	const int sizeR = row + 1;
	const int sizeC = column + 1;

	int **pScore = new int*[sizeR];  //二维指针
	for (int i = 0; i <= row; i++)
		pScore[i] = new int[sizeC];

	//初始化第一行和第一列
	for (int c = 0; c <= column; c++)
		pScore[0][c] = 0 - c;
	for (int r = 0; r <= row; r++)
		pScore[r][0] = 0 - r;

	//从v(1,1)开始每列计算
	for (int c = 1; c <= column; c++)
	{
		for (int r = 1; r <= row; r++)
		{
			//计算v(i,j)
			int valueMatch;
			if (vStrColumn[r - 1] == vStrRow[c - 1])
				valueMatch = MATCH;
			else
				valueMatch = MISS_MATCH;
			int A = pScore[r - 1][c] + INSERT;
			int B = pScore[r][c - 1] + DELETE;
			int C = pScore[r - 1][c - 1] + valueMatch;
			pScore[r][c] = getMaxValue(A, B, C);
		}
	}

	//计算编辑距离
	int r = row, c = column;
	while (r > 0 && c > 0)
	{
		if (pScore[r][c] + 1 == pScore[r - 1][c])
		{
			editDis++;
			r--;
			continue;
		}
		else if (pScore[r][c] + 1 == pScore[r][c - 1])
		{
			editDis++;
			c--;
			continue;
		}
		else if (pScore[r][c] + 1 == pScore[r - 1][c - 1])
		{
			editDis++;
			r--;
			c--;
			continue;
		}
		else
		{
			r--;
			c--;
		}
	}
	if (r > 0 && c == 0)  editDis += r;
	else if (c > 0 && r == 0) editDis += c;

	std::cout << std::endl;
	//----------------DEBUG-------------------//
	//打印数据
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= column; j++)
			std::cout << std::setw(2) << pScore[j] << "  ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//设置编辑距离和得分
	setEditDis(editDis);
	setScore(pScore[row][column]);

	for (int i = 0; i <= row; i++)   //释放内存
	{
		delete pScore;
		pScore = NULL;
	}
	delete[] pScore;
}
