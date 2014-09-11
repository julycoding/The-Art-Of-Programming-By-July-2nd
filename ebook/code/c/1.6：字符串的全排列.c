#include "stdio.h"
#include "windows.h"

void swap(char &c1, char &c2)
{
	char temp = c1;
	c1 = c2;
	c2 = temp;
}

void reverse(char *from, char *to)
{
	while (from < to)
	{
		swap(*from++, *to--);
	}
}

int partition(char *c, int num)
{
	int i, j = -1;
	for (i = 0; i < num - 1; ++i)
	{
		if (c[i] <= c[num - 1])
		{
			++j;
			swap(c[i], c[j]);
		}
	}
	swap(c[num - 1], c[j + 1]);

	return j + 1;
}

void quickSort(char *c, int num)
{
	int i;
	if (num > 0)
	{
		i = partition(c, num);
		quickSort(c, i);
		quickSort(c + i + 1, num - i - 1);
	}	
}

//解法一
void calcAllPermutation(char* perm, int from, int to)
{
	if (from > to || to < 0)
	{
		return;
	}

	if (from == to)
	{
		for (int i = 0; i <= to; i++)
			printf("%c", perm[i]);
		printf("\n");
	}
	else
	{
		calcAllPermutation(perm, from + 1, to);
		for (int j = from + 1; j <= to; j++)
		{
			swap(perm[j], perm[from]);
			calcAllPermutation(perm, from + 1, to);
			swap(perm[j], perm[from]);
		}
	}
}

//解法二
void calcAllPermutation(char* perm, int num)
{
	if (num < 1)
		return;

	quickSort(perm, num);

	for (int i = 0; i < num; i++)
	{
		printf("%c", perm[i]);
	}
	printf("\n");

	while (true)
	{
		int i;
		for (i = num - 2; i >= 0; --i)
		{
			if (perm[i] < perm[i + 1])
				break ;
		}

		if (i < 0)
		{
			break ;  // 已经找到所有排列
		}

		int k;
		for (k = num - 1; k > i; --k)
		{
			if (perm[k] > perm[i])
				break ;
		}

		swap(perm[i], perm[k]);

		// reverse 左右均闭合， 与stl的reverse不同
		reverse(perm + i + 1, perm + num - 1);

		for (i = 0; i < num; i++)
		{
			printf("%c", perm[i]);
		}
		printf("\n");
	}
}

int main()
{
	char a[] = "4321";
	printf("%s所有全排列的结果为：\n", &a);

	printf("Solution 1:\n");
	calcAllPermutation(a, 0, strlen(a) - 1);

	printf("\nSolution 2：\n");
	calcAllPermutation(a, strlen(a));

	system("pause");
	return 0;
}
