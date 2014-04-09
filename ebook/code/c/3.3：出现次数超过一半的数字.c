//解法五
//改自编程之美 2010  
Type Find(Type* a, int N)  //a代表数组，N代表数组长度  
{  
	Type candidate;  
	int nTimes, i;  
	for(i = nTimes = 0; i < N; i++)  
	{  
		if(nTimes == 0)  
		{  
			candidate = a[i], nTimes = 1;  
		}  
		else  
		{  
			if(candidate == a[i])  
				nTimes++;  
			else  
				nTimes--;  
		}  
	}  
	return candidate;   
}

//解法五②
//copyright@zhedahht  
//July,updated,  
//2011.04.16。  
#include <iostream>  
using namespace std;  

bool g_Input = false;  

int Num(int* numbers, unsigned int length)  
{  
	if(numbers == NULL && length == 0)  
	{  
		g_Input = true;  
		return 0;  
	}  
	g_Input = false;  

	int result = numbers[0];  
	int times = 1;  
	for(int i = 1; i < length; ++i)  
	{  
		if(numbers[i] == result)  
			times++;  
		else  
			times--;  
		if(times == 0)  
		{  
			result = numbers[i];  
			times = 1;  
		}  
	}  

	//检测输入是否有效。  
	times = 0;  
	for(i = 0; i < length; ++i)  
	{  
		if(numbers[i] == result)  
			times++;  
	}  
	if(times * 2 <= length)  
		//检测的标准是：如果数组中并不包含这么一个数字，那么输入将是无效的。  
	{  
		g_Input = true;  
		result = 0;  
	}      
	return result;  
}  

int main()  
{  
	int a[10]={1,2,3,4,6,6,6,6,6};  
	int* n=a;  
	cout<<Num(a,9)<<endl;  
	return 0;  
}


//问题扩展代码①
#include<iostream>  
using namespace std;  

int Find(int* a, int N)  
{  
	int candidate1,candidate2;  
	int nTimes1, nTimes2, i;  

	for(i = nTimes1 = nTimes2 =0; i < N; i++)  
	{  
		if(nTimes1 == 0)  
		{  
			candidate1 = a[i], nTimes1 = 1;  
		}  
		else if(nTimes2 == 0 && candidate1 != a[i])  
			//注意：这里的判断条件加上第二个变量是否等于第一个变量的判断  
		{  

			candidate2 = a[i], nTimes2 = 1;  
		}  
		else  
		{  
			if(candidate1 == a[i])  
				nTimes1++;  
			else if(candidate2 == a[i])  
				nTimes2++;  
			else  
			{  
				nTimes1--;  
				nTimes2--;  
			}  
		}  
	}  
	return nTimes1>nTimes2?candidate1:candidate2;  
}  

int main()  
{  
	int a[4]={0,1,2,1};  
	cout<<Find(a,4)<<endl;  
	//  int a[6]={1,0,2,1,2,1};  
	//  cout<<Find(a,6)<<endl;  
}

//问题扩展代码②
int Find(int* a, int N)  //a代表数组，N代表数组长度      
{      
	int candidate;      
	int nTimes, i;      
	for(i = nTimes = 0; i < N; i++)      
	{      
		if(nTimes == 0)      
		{      
			candidate = a[i], nTimes = 1;      
		}      
		else      
		{      
			if(candidate == a[i])      
				nTimes++;      
			else      
				nTimes--;      
		}      
	}      

	int cTimes = 0;    
	int candidate2 = a[N-1];    
	for(i = 0; i < N; i ++)    
	{    
		if(a[i] == candidate)    
		{    
			cTimes++;    
		}    
	}    

	return cTimes == N/2 ? candidate : candidate2;       
}
