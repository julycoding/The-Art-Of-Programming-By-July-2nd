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


//解法三、代码①
double func(double *a, const int n)
{
	double *maxA = new double[n];
	double *minA = new double[n];
	maxA[0] = minA[0] = a[0];
	double value = maxA[0];
	for (int i = 1 ; i < n ; ++i)
	{
		maxA[i] = max(max(a[i], maxA[i - 1] * a[i]), minA[i - 1] * a[i]);
		minA[i] = min(min(a[i], maxA[i - 1] * a[i]), minA[i - 1] * a[i]);
		value = max(value, maxA[i]);
	}
	return value;
}


//解法三、代码②
/*
 给定一个浮点数数组，有正有负数，0，正数组成,数组下标从1算起
 求最大连续子序列乘积，并输出这个序列，如果最大子序列乘积为负数，那么就输出-1
 用Max[i]表示以a[i]结尾乘积最大的连续子序列
 用Min[i]表示以a[i]结尾乘积最小的连续子序列  因为有复数，所以保存这个是必须的
*/
void longest_multiple(double *a, int n)
{
    double *Min = new double[n + 1]();
    double *Max = new double[n + 1]();
    double *p = new double[n + 1]();
    //初始化
    for (int i = 0; i <= n; i++)
    {
        p[i] = -1;
    }
    Min[1] = a[1];
    Max[1] = a[1];
    double max_val = Max[1];
    for (int i = 2; i <= n; i++)
    {
        Max[i] = max(Max[i - 1] * a[i], Min[i - 1] * a[i], a[i]);
        Min[i] = min(Max[i - 1] * a[i], Min[i - 1] * a[i], a[i]);
        if (max_val < Max[i])
            max_val = Max[i];
    }
    if (max_val < 0)
        printf("%d", -1);
    else
        printf("%d", max_val);
    //内存释放
    delete [] Max;
    delete [] Min;
}
