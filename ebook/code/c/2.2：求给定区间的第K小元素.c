//伴随数组解法
//copyright@ 水 && July  
//总的时间复杂度为O（N*logN+N）= O（N*logN）。  
//July、updated，2011.05.28.凌晨。  
#include<iostream>  
#include<algorithm>  
using namespace std;  

struct node{  
	int num,data;  
	bool operator < (const node &p) const   
	{  
		return data < p.data;  
	}  
};  
node p[100001];  

int main()  
{  
	int n=7;  
	int i,j,a,b,c;//c：flag;  

	for(i=1;i<=n;i++)   
	{  
		scanf("%d",&p[i].data);  
		p[i].num = i;  
	}  
	sort(p+1,p+1+n);    //调用库函数sort完成排序，复杂度n*logn  

	scanf("%d %d %d",&a,&b,&c);  
	for(i=1;i<=n;i++)   //扫描一遍，复杂度n  
	{  
		if(p[i].num>=a && p[i].num<=b)   
			c--;   
		if(c == 0)   
			break;  
	}  
	printf("%d/n",p[i].data);  
	return 0;  
}  


//问题扩展部分
//copyright@ 苍狼  
//直接对给定区间的数进行排序，没必要用伴随数组。  
#include<iostream>     
#include<algorithm>     
using namespace std;     

struct node{     
	int data;     
	bool operator < (const node &p) const      
	{     
		return data < p.data;     
	}     
};     
node p[100001];     

int main()     
{     
	int n=7;     
	int i,a,b,c;//c：flag;     

	for(i=1;i<=n;i++)      
	{     
		scanf("%d",&p[i].data);        
	}  

	scanf("%d%d%d", &a, &b, &c);   //b，a为原数组的下标索引  
	sort(p+a, p+b+1);     //直接对给定区间进行排序，|b-a+1|*log（b-a+1）  

	printf("The number is %d/n", p[a-1+c].data);      
	return 0;     
}  
