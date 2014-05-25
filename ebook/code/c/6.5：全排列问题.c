//解法一、代码①
template <typename T>
void CalcAllPermutation_R(T perm[], int first, int num)
{
	if (num <= 1)
	{
		return;
	}

	for (int i = first; i < first + num; ++i)
	{
		swap(perm[i], perm[first]);
		CalcAllPermutation_R(perm, first + 1, num - 1);
		swap(perm[i], perm[first]);
	}
}


//解法一、代码②
void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if (!pStr || !pBegin)
		return;

	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++ pCh)
		{
			// swap pCh and pBegin
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);
			// restore pCh and pBegin
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}


//解法二
template <typename T>
void CalcAllPermutation(T perm[], int num)
{
	if (num < 1)
		return;

	while (true)
	{
		int i;
		for (i = num - 2; i >= 0; --i)
		{
			if (perm[i] < perm[i + 1])
				break;
		}

		if (i < 0)
			break;  // 已经找到所有排列

		int k;
		for (k = num - 1; k > i; --k)
		{
			if (perm[k] > perm[i])
				break;
		}

		swap(perm[i], perm[k]);
		reverse(perm + i + 1, perm + num);

	}
}


//类似问题
//假设str已经有序，from 一直很安静  
void perm(char *str, int size, int resPos)  
{  
	if(resPos == size)  
		print(result);  
	else  
	{  
		for(int i = 0; i < size; ++i)  
		{  
			result[resPos] = str[i];  
			perm(str, size, resPos + 1);  
		}  
	}  
}  
