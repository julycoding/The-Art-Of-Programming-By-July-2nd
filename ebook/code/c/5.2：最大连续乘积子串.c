//解法一
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

double maxProductSubstring(double *a, int length) 
{
	double maxResult = 0;
	double start = 0;
	double end = 0;
	for (int i = 0; i < length; i++)
	{
		double x = a[i];
		for (int j = i + 1; j < length; j++)
		{
			x *= a[j];
			if (x > maxResult)
			{
				maxResult = x;
				start = a[i];
				end = a[j];
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
	int i;
	double maxProduct = 1;
	double minProduct = 1;
	double maxCurrent = 1;
	double minCurrent = 1;

	for (i = 0; i < length; i++)
	{
		maxCurrent *= a[i];
		minCurrent *= a[i];
		if (maxCurrent > maxProduct)
			maxProduct = maxCurrent;
		if (minCurrent > maxProduct)
			maxProduct = minCurrent;
		if (maxCurrent < minProduct)
			minProduct = maxCurrent;
		if (minCurrent < minProduct)
			minProduct = minCurrent;
		if (minCurrent > maxCurrent)
			swap(maxCurrent, minCurrent);
		if (maxCurrent < 1)
			maxCurrent = 1;
	}
	return maxProduct;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double a[] = { -2.5, 4, 0, 3, 0.5, 8, -1 };
	cout << maxProductSubstring(a, 7) << endl;
	return 0;
}


//解法三
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

double maxProductSubstring(double *a, int length) 
{
	double maxEnd = a[0];
	double minEnd = a[0];
	double maxResult = a[0];
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
	double a[] = { -2.5,4,0,3,0.5,8,-1};
	cout << maxProductSubstring(a, 7) << endl;
	return 0;
}
