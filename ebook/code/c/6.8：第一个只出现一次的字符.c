//代码一
#include <iostream>
using namespace std;

//查找第一个只出现一次的字符，第1个程序
//copyright@ Sorehead && July
//July、updated，2011.04.24.
char find_first_unique_char(char *str)
{
	int data[256];
	char *p;

	if (str == NULL)
		return '\0';

	memset(data, 0, sizeof(data));    //数组元素先全部初始化为0
	p = str;
	while (*p != '\0')
		data[(unsigned char)*p++]++;  //遍历字符串，在相应位置++，（同时，下标强制转换）

	while (*str != '\0')
	{
		if (data[(unsigned char)*str] == 1)  //最后，输出那个第一个只出现次数为1的字符
			return *str;

		str++;
	}

	return '\0';
}

int main()
{
	char *str = "afaccde";
	cout << find_first_unique_char(str) << endl;
	return 0;
}

//代码二
//查找第一个只出现一次的字符，第2个程序
//copyright@ yansha
//July、updated，2011.04.24.
char FirstNotRepeatChar(char* pString)
{
	if (!pString)
		return '\0';

	const int tableSize = 256;
	int hashTable[tableSize] = {0}; //存入数组，并初始化为0

	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)]++;

	while (*pString != '\0')
	{
		if (hashTable[*pString] == 1)
			return *pString;

		pString++;
	}
	return '\0';  //没有找到满足条件的字符，退出
}
