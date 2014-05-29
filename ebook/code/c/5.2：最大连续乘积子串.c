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
template <typename Comparable>
Comparable maxprod( const vector<Comparable>&v)
{
	int i;
	Comparable maxProduct = 1;
	Comparable minProduct = 1;
	Comparable maxCurrent = 1;
	Comparable minCurrent = 1;
	//Comparable t;

	for ( i = 0; i < v.size() ; i++)
	{
		maxCurrent *= v[i];
		minCurrent *= v[i];
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
		//if(minCurrent>1)
		//    minCurrent =1;
	}
	return maxProduct;
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
