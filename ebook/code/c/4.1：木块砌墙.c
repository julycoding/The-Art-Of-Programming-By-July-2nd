//copyright@红色标记 12/8/2013    
//updated@July 13/8/2013  
using System;    
using System.Collections.Generic;    
using System.Text;    
using System.Collections;    

namespace HeapBlock    
{    
	public class WoolWall    
	{            
		private int n;    
		private int height;    
		private int maxState;    
		private int[, ,] resultCache;   //结果缓存数组    

		public WoolWall(int n, int height)    
		{    
			this.n = n;    
			this.height = height;    
			maxState = (1 << height) - 1;    
			resultCache = new int[n + 1, maxState + 1, maxState + 1];   //构建缓存数组，每个值默认为0；    
		}    

		/// <summary>    
		/// 静态入口。计算堆放方案数。    
		/// </summary>    
		/// <param name="n"></param>    
		/// <param name="k"></param>    
		/// <returns></returns>    
		public static int Heap(int n, int k)    
		{    
			return new WoolWall(n, k).Heap();    
		}    

		/// <summary>    
		/// 计算堆放方案数。    
		/// </summary>    
		/// <returns></returns>    
		public int Heap()    
		{    
			return (int)Heap(n, 0, 0);    
		}    

		private long Heap(int n, int lState, int rState)    
		{    
			//如果缓存数组中的值不为0，则表示该结果已经存在缓存中。    
			//直接返回缓存结果。    
			if (resultCache[n, lState, rState] != 0)    
			{    
				return resultCache[n, lState, rState];    
			}    

			//在只有一列的情况，无法再进行切分    
			//根据列状态计算一列的堆放方案    
			if (n == 0)    
			{    
				return CalcOneColumnHeapCount(lState);    
			}    

			long result = 0;    
			for (int state = 0; state <= maxState; state++)    
			{    
				if (n == 1)    
				{    
					//在只有两列的情况，判断当前状态在切分之后是否有效    
					if (!StateIsAvailable(n, lState, rState, state))    
					{    
						continue;    
					}    
					result += Heap(n - 1, state | lState, state | lState)  //合并状态。因为只有一列，所以lState和rState相同。    
						* Heap(n - 1, state | rState, state | rState);    
				}    
				else    
				{    
					result += Heap(n - 1, lState, state) * Heap(n - 1, state, rState);     
				}    
				result %= 1000000007;//为了防止结果溢出，根据题目要求求模。    
			}    

			resultCache[n, lState, rState] = (int)result;   //将结果写入缓存数组中    
			resultCache[n, rState, lState] = (int)result;   //对称的墙结果相同，所以直接写入缓存。    
			return result;    
		}    

		/// <summary>    
		/// 根据一列的状态，计算列的堆放方案数。    
		/// </summary>    
		/// <param name="state">状态</param>    
		/// <returns></returns>    
		private int CalcOneColumnHeapCount(int state)    
		{    
			int sn = 0; //连续计数    
			int result = 1;    
			for (int i = 0; i < height; i++)    
			{    
				if ((state & 1) == 0)    
				{    
					sn++;    
				}    
				else    
				{    
					if (sn > 0)    
					{    
						result *= CalcAllState(sn);    
					}    
					sn = 0;    
				}    
				state >>= 1;    
			}    
			if (sn > 0)    
			{    
				result *= CalcAllState(sn);    
			}    

			return result;    
		}    

		/// <summary>    
		/// 类似于斐波那契序列。    
		/// f(1)=1    
		/// f(2)=2    
		/// f(n) = f(n-1)*f(n-2);    
		/// 只是初始值不同。    
		/// </summary>    
		/// <param name="k"></param>    
		/// <returns></returns>    
		private static int CalcAllState(int k)    
		{    
			return k <= 2 ? k : CalcAllState(k - 1) + CalcAllState(k - 2);    
		}    

		/// <summary>    
		/// 判断状态是否可用。    
		/// 当n=1时，分割之后，左墙和右边墙只有一列。    
		/// 所以state的状态码可能会覆盖原来的边缘状态。    
		/// 如果有覆盖，则该状态不可用；没有覆盖则可用。    
		/// 当n>1时，不存在这种情况，都返回状态可用。    
		/// </summary>    
		/// <param name="n"></param>    
		/// <param name="lState">左边界状态</param>    
		/// <param name="rState">右边界状态</param>    
		/// <param name="state">切开位置的当前状态</param>    
		/// <returns>状态有效返回 true,状态不可用返回 false</returns>    
		private bool StateIsAvailable(int n, int lState, int rState, int state)    
		{    
			return (n > 1) || ((lState | state) == lState + state && (rState | state) == rState + state);    
		}    
	}    
}    


//解法三
//copyright@caopengcs 12/08/2013  
#ifdef WIN32  
#define ll __int64   
#else  
#define ll long long  
#endif  

// 1 covered 0 uncovered  

void cal(int a[6][32][32],int n,int col,int laststate,int nowstate)
{
	if (col >= n)
	{
		++a[n][laststate][nowstate];  
		return;  
	}  
	//不填 或者用1*1的填  
	cal(a,n, col + 1, laststate, nowstate);  
	if (((laststate >> col) & 1) == 0)
	{
		cal(a,n, col + 1, laststate, nowstate | (1 << col));  
		if ((col + 1 < n) && (((laststate >> (col + 1)) & 1) == 0))
		{
			cal(a,n, col + 2, laststate, nowstate);  
		}  
	}  
}  

inline int mul(ll x, ll y)
{
	return x * y % 1000000007;  
}  

void multiply(int n,int a[][32],int b[][32])
{ // b = a * a
	int i,j, k;  
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			for (k = b[i][j] = 0; k < n; ++k)
			{
				if ((b[i][j] += mul(a[i][k],a[k][j])) >= 1000000007)
				{
					b[i][j] -= 1000000007;
				}  
			}  
		}  
	}  
}  

int calculate(int n,int k)
{
	int i, j;  
	int a[6][32][32],mat[2][32][32];  
	memset(a,0,sizeof(a));  
	for (i = 1; i <= 5; ++i)
	{
		for (j = (1 << i) - 1; j >= 0; --j)
		{
			cal(a,i, 0, j, 0);  
		}  
	}  
	memcpy(mat[0], a[k],sizeof(mat[0]));  
	k = (1 << k);  
	for (i = 0; n; --n)
	{
		multiply(k, mat[i], mat[i ^ 1]);  
		i ^= 1;  
	}  
	return mat[i][0][0];  
}  
