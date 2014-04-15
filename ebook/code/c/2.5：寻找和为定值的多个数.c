//解法一
// 21题递归方法
//copyright@ July && yansha
//July、yansha，updated。
#include<list>
#include<iostream>
using namespace std;

list<int>list1;
void find_factor(int sum, int n)
{
	// 递归出口
	if(n <= 0 || sum <= 0)
		return;

	// 输出找到的结果
	if(sum == n)
	{
		// 反转list
		list1.reverse();
		for(list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
			cout << *iter << " + ";
		cout << n << endl;
		list1.reverse();
	}

	list1.push_front(n);      //典型的01背包问题
	find_factor(sum-n, n-1);   //放n，n-1个数填满sum-n
	list1.pop_front();
	find_factor(sum, n-1);     //不放n，n-1个数填满sum
}

int main()
{
	int sum, n;
	cout << "请输入你要等于多少的数值sum:" << endl;
	cin >> sum;
	cout << "请输入你要从1.....n数列中取值的n：" << endl;
	cin >> n;
	cout << "所有可能的序列，如下：" << endl;
	find_factor(sum,n);
	return 0;
}


//解法二
//copyright@ 2011 zhouzhenren

//输入两个整数 n 和 m，从数列1，2，3.......n 中 随意取几个数,
//使其和等于 m ,要求将其中所有的可能组合列出来。

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * 输入t， r， 尝试Wk
 */
void sumofsub(int t, int k ,int r, int& M, bool& flag, bool* X)
{
    X[k] = true;   // 选第k个数
    if (t + k == M) // 若找到一个和为M，则设置解向量的标志位，输出解
    {
        flag = true;
        for (int i = 1; i <= k; ++i)
        {
            if (X[i] == 1)
            {
                printf("%d ", i);
            }
        }
        printf("/n");
    }
    else
    {   // 若第k+1个数满足条件，则递归左子树
        if (t + k + (k+1) <= M)
        {
            sumofsub(t + k, k + 1, r - k, M, flag, X);
        }
        // 若不选第k个数，选第k+1个数满足条件，则递归右子树
        if ((t + r - k >= M) && (t + (k+1) <= M))
        {
            X[k] = false;
            sumofsub(t, k + 1, r - k, M, flag, X);
        }
    }
}

void search(int& N, int& M)
{
    // 初始化解空间
    bool* X = (bool*) malloc(sizeof(bool) * (N+1));
    memset(X, false, sizeof(bool) * (N+1));
    int sum = (N + 1) * N * 0.5f;
    if (1 > M || sum < M) // 预先排除无解情况
    {
        printf("not found/n");
        return;
    }
    bool f = false;
    sumofsub(0, 1, sum, M, f, X);
    if (!f)
    {
        printf("not found/n");
    }
    free(X);
}

int main()
{
    int N, M;
    printf("请输入整数N和M/n");
    scanf("%d%d", &N, &M);
    search(N, M);
    return 0;
}


//问题扩展
/**
* The problem:
* 从一列数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的（网易）。
* use binary search, perhaps you should compile it with -std=c99
* fairywell 2011
*/
#include <stdio.h>

#define MAX_NUM    (1U<<31)

int
main()
{
    int i, n, low, high, mid, max;

    printf("Input how many numbers there are: ");
    scanf("%d/n", &n);
    /* a[] holds the numbers, b[i] holds the number of increasing numbers
    * from a[0] to a[i], c[i] holds the number of increasing numbers
    * from a[n-1] to a[i]
    * inc[] holds the increasing numbers
    * VLA needs c99 features, compile with -stc=c99
    */
    double a[n], b[n], c[n], inc[n];

    printf("Please input the numbers:/n");
    for (i = 0; i < n; ++i) scanf("%lf", &a[i]);

    // update array b from left to right
    for (i = 0; i < n; ++i) inc[i] = (unsigned) MAX_NUM;
    //b[0] = 0;
    for (i = 0; i < n; ++i) {
        low = 0; high = i;
        while (low < high) {
            mid = low + (high-low)*0.5;
            if (inc[mid] < a[i]) low = mid + 1;
            else high = mid;
        }
        b[i] = low + 1;
        inc[low] = a[i];
    }

    // update array c from right to left
    for (i = 0; i < n; ++i) inc[i] = (unsigned) MAX_NUM;
    //c[0] = 0;
    for (i = n-1; i >= 0; --i) {
        low = 0; high = i;
        while (low < high) {
            mid = low + (high-low)*0.5;
            if (inc[mid] < a[i]) low = mid + 1;
            else high = mid;
        }
        c[i] = low + 1;
        inc[low] = a[i];
    }

    max = 0;
    for (i = 0; i < n; ++i )
        if (b[i]+c[i] > max) max = b[i] + c[i];
        printf("%d number(s) should be erased at least./n", n+1-max);
        return 0;
}
