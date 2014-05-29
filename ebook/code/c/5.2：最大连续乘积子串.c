//解法一
double max = 0;
double start = 0;
double end = 0;
for (int i = 0; i < num; i++)
{
	double x = arrs[i];
	for (int j = i + 1; j < num; j++)
	{
		x *= arrs[j];
		if (x > max)
		{
			max = x;
			start = arrs[i];
			end = arrs[j];
		}
	}
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
	double maxend = a[0];
	double minend = a[0];
	double result = a[0];
	for (int i = 1; i < length; ++i) 
	{
		double end1 = maxend * a[i], end2 = minend * a[i];
		maxend = max(max(end1, end2), a[i]);
		minend = min(min(end1, end2), a[i]);
		result = max(result, maxend);
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double a[] = { -2.5,4,0,3,0.5,8,-1};
	cout << maxProductSubstring(a, 7) << endl;
	return 0;
}
