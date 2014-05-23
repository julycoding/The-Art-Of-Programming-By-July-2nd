//解法一
int maxSubArray(int* A, int n)
{
    int maxSum = -INF;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                currSum += A[k];
            }
            if (currSum > maxSum)
                maxSum = currSum;

            currSum = 0; //这里要记得清零，否则的话sum最终存放的是所有子数组的和。
        }
    }
    return maxSum;
}


//解法二
#include <iostream>
using namespace std;

int maxSubArray(int* a, int n)
{
	int maxSum = a[0];       //全负情况，返回最大数
	int currSum = 0;
	for (int j = 0; j < n; j++)
	{
		if (currSum >= 0)    //如果加上某个元素，sum>=0的话，就加
			currSum += a[j];
		else
			currSum = a[j];  //如果加上某个元素，sum<0了，就不加
		if (currSum > maxSum)
			maxSum = currSum;
	}
	return maxSum;
}

int main()
{
	int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << maxSubArray(a,8) << endl;
	//int a[] = { -1, -2, -3, -4 };
	//cout << maxSubArray(a,4) << endl;
	return 0;
}


//解法三：动态规划的解法
#include <iostream>
using namespace std;

int maxSubArray(int* a, int n)
{
	if (a == nullptr || n == 0)
		return 0;

	int currSum = 0;
	int maxSum = a[0];       //全负情况，返回最大数

	for (int j = 0; j < n; j++)
	{
		currSum = (a[j] > currSum + a[j]) ? a[j] : currSum + a[j];
		maxSum = (maxSum > currSum) ? maxSum : currSum;

	}
	return maxSum;
}

int main()
{
	int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << maxSubArray(a, 8) << endl;
	//int a[] = { -1, -2, -3, -4 };
	//cout << maxSubArray(a,4) << endl;
	return 0;
}
