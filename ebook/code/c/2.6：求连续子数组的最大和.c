//解法一
//本段代码引自编程之美
int MaxSum(int* A, int n)
{
	int maximum = -INF;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				sum += A[k];
			}
			if (sum > maximum)
				maximum = sum;

			sum = 0; //这里要记得清零，否则的话sum最终存放的是所有子数组的和。也就是编程之美上所说的bug。多谢苍狼。
		}
	}
	return maximum;
}


//解法二
//copyright@ July 2010/10/18
//updated，2011.05.25.
#include <iostream.h>

int maxSum(int* a, int n)
{
    int sum = 0;
    //其实要处理全是负数的情况，很简单，如稍后下面第3点所见，直接把这句改成："int sum=a[0]"即可
    //也可以不改，当全是负数的情况，直接返回0，也不见得不行。
    int b = 0;

    for (int i = 0; i < n; i++)
    {
        if (b < 0)
            b = a[i];
        else
            b += a[i];
        if (sum < b)
            sum = b;
    }
    return sum;
}

int main()
{
    int a[10] = {1, -2, 3, 10, -4, 7, 2, -5};
    //int a[] = {-1,-2,-3,-4};  //测试全是负数的用例
    cout << maxSum(a, 8) << endl;
    return 0;
}

/*-------------------------------------
  解释下：
  例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，
  那么最大的子数组为3, 10, -4, 7, 2，
  因此输出为该子数组的和18。

  所有的东西都在以下俩行，
  即：
  b  ：  0  1  -1  3  13   9  16  18  13
  sum：  0  1   1  3  13  13  16  18  18

  其实算法很简单，当前面的几个数，加起来后，b<0后，
  把b重新赋值，置为下一个元素，b=a[i]。
  当b>sum，则更新sum=b;
  若b<sum，则sum保持原值，不更新。。July、10/31。
  ----------------------------------*/

//处理负数
//copyright@ July
//July、updated，2011.05.25。
#include <iostream.h>
#define n 4           //多定义了一个变量

int maxsum(int a[n])
	//于此处，你能看到上述思路2代码（指针）的优势
{
	int max = a[0];       //全负情况，返回最大数
	int sum = 0;
	for (int j = 0; j < n; j++)
	{
		if (sum >= 0)    //如果加上某个元素，sum>=0的话，就加
			sum += a[j];
		else
			sum = a[j];  //如果加上某个元素，sum<0了，就不加
		if (sum > max)
			max = sum;
	}
	return max;
}

int main()
{
	int a[] = { -1, -2, -3, -4};
	cout << maxsum(a) << endl;
	return 0;
}


//问题扩展
//感谢网友firo
//July、2010.06.05。

//Algorithm 1:时间效率为O(n*n*n)
int MaxSubsequenceSum1(const int A[], int N)
{
	int ThisSum = 0 , MaxSum = 0, i, j, k;
	for (i = 0; i < N; i++)
		for (j = i; j < N; j++)
		{
			ThisSum = 0;
			for (k = i; k < j; k++)
				ThisSum += A[k];

			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
		return MaxSum;
}

//Algorithm 2:时间效率为O(n*n)
int MaxSubsequenceSum2(const int A[], int N)
{
	int ThisSum = 0, MaxSum = 0, i, j, k;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

//Algorithm 3:时间效率为O(n*log n)
//算法3的主要思想：采用二分策略，将序列分成左右两份。
//那么最长子序列有三种可能出现的情况，即
//【1】只出现在左部分.
//【2】只出现在右部分。
//【3】出现在中间，同时涉及到左右两部分。
//分情况讨论之。
static int MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;             //左、右部分最大连续子序列值。对应情况【1】、【2】
	int MaxLeftBorderSum, MaxRightBorderSum; //从中间分别到左右两侧的最大连续子序列值，对应case【3】。
	int LeftBorderSum, RightBorderSum;
	int Center, i;
	if (Left == Right)Base Case
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;
	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);
	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}
	int max1 = MaxLeftSum > MaxRightSum ? MaxLeftSum : MaxRightSum;
	int max2 = MaxLeftBorderSum + MaxRightBorderSum;
	return max1 > max2 ? max1 : max2;
}

//Algorithm 4:时间效率为O(n)
//同上述第一节中的思路3、和4。
int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, j;
	ThisSum = MaxSum = 0;
	for (j = 0; j < N; j++)
	{
		ThisSum += A[j];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}
