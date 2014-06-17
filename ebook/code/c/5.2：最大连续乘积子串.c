//解法一
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

double maxProductSubstring(double *a, int length) 
{
	double maxResult = a[0];
	for (int i = 0; i < length; i++)
	{
		double x = 1;
		for (int j = i; j < length; j++)
		{
			x *= a[j];
			if (x > maxResult)
			{
				maxResult = x;
			}
		}
	}
	return maxResult;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double a[] = { -2.5,4,0,3,0.5,8,-1};
	cout << maxProductSubstring(a, 7) << endl;
	return 0;
}


//解法二
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

double maxProductSubstring(double *a, int length)
{
	double maxEnd = a[0];
	double minEnd = a[0];
	double maxResult = a[0];
	// {-3,-0.5,-10}
	for (int i = 1; i < length; ++i)
	{
		double end1 = maxEnd * a[i], end2 = minEnd * a[i];
		maxEnd = max(max(end1, end2), a[i]);
		minEnd = min(min(end1, end2), a[i]);
		maxResult = max(maxResult, maxEnd);
	}
	return maxResult;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double a[] = { -3, -0.5,- 10};
	cout << maxProductSubstring(a, 3) << endl;
	return 0;
}
