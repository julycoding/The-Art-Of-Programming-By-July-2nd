//解法二
//思路，很简答，俩指针，一首一尾  
//如果第一个指针指向的数字是偶数而第二个指针指向的数字是奇数，  
//我们就交换这两个数字  

// 2 1 3 4 6 5 7   
// 7 1 3 4 6 5 2  
// 7 1 3 5 6 4 2  

//如果限制空间复杂度为O（1），时间为O（N），且奇偶数之间相对顺序不变，就相当于正负数间顺序调整的那道题了。  

//copyright@2010 zhedahht。
void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);
void ReorderOddEven(int *pData, unsigned int length)
{
	if (pData == NULL || length == 0)
		return;

	Reorder(pData, length, isEven);
}
void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
	if (pData == NULL || length == 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		// if *pBegin does not satisfy func, move forward
		if (!func(*pBegin))  //如果是奇数, 则向后移一个位置
		{
			pBegin ++;
			continue;
		}

		// if *pEnd does not satisfy func, move backward
		if (func(*pEnd))     //如是是偶数, 则向前移一个位置
		{
			pEnd --;
			continue;
		}
		// if *pBegin satisfy func while *pEnd does not,
		// swap these integers
		int temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
	}
}
bool isEven(int n)
{
	return (n & 1) == 0;
}
