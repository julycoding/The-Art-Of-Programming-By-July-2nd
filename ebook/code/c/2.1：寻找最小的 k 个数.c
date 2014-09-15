//解法四
//copyright@ mark allen weiss  
//July、updated，2011.05.05凌晨.  

//q_select places the kth smallest element in a[k]  
void q_select( input_type a[], int k, int left, int right )  
{  
	int i, j;
	input_type pivot;
	if( left + CUTOFF <= right )  
	{
		pivot = median3( a, left, right );
		//取三数中值作为枢纽元，可以消除最坏情况而保证此算法是O（N）的。不过，这还只局限在理论意义上。  
		//稍后，除了下文的第二节的随机选取枢纽元，在第四节末，您将看到另一种选取枢纽元的方法。  

		i=left; j=right-1;
		for(;;)
		{
			while( a[++i] < pivot );
			while( a[--j] > pivot );
			if (i < j )
				swap( &a[i], &a[j] );
			else
				break;
		}
		swap( &a[i], &a[right-1] ); /* restore pivot */
		if( k < i)
			q_select( a, k, left, i-1 );
		else
			if( k > i )
				q-select( a, k, i+1, right );
	}  
	else
		insert_sort(a, left, right );
}


//解法五
PARTITION(A, p, r)         //partition过程 p为第一个数，r为最后一个数
	1  x ← A[r]               //以最后一个元素作为主元
2  i ← p - 1
	3  for j ← p to r - 1
	4       do if A[j] ≤ x
	5             then i ← i + 1
	6                  exchange A[i] <-> A[j]
7  exchange A[i + 1] <-> A[r]
8  return i + 1

	RANDOMIZED-PARTITION(A, p, r)      //随机快排的partition过程
	1  i ← RANDOM(p, r)                                 //i  随机取p到r中个一个值
	2  exchange A[r] <-> A[i]                         //以随机的 i作为主元
3  return PARTITION(A, p, r)            //调用上述原来的partition过程

	RANDOMIZED-SELECT(A, p, r, i)       //以线性时间做选择，目的是返回数组A[p..r]中的第i 小的元素
	1  if p = r          //p=r，序列中只有一个元素
	2      then return A[p]
3  q ← RANDOMIZED-PARTITION(A, p, r)   //随机选取的元素q作为主元
	4  k ← q - p + 1                     //k表示子数组 A[p…q]内的元素个数，处于划分低区的元素个数加上一个主元元素
	5  if i == k                        //检查要查找的i 等于子数组中A[p....q]中的元素个数k
	6      then return A[q]        //则直接返回A[q]
7  else if i < k
	8      then return RANDOMIZED-SELECT(A, p, q - 1, i)
	//得到的k 大于要查找的i 的大小，则递归到低区间A[p，q-1]中去查找
	9  else return RANDOMIZED-SELECT(A, q + 1, r, i - k)
	//得到的k 小于要查找的i 的大小，则递归到高区间A[q+1，r]中去查找。  


//...

//解法四示例
#include <stdio.h>
#define Cutoff ( 3 )

void swap( int *a, int *b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int median3( int a[ ], int left, int right )
{
    int Center = ( left + right ) / 2;

    if( a[ left ] > a[ Center ] )
        swap( &a[ left ], &a[ Center ] );
    if( a[ left ] > a[ right ] )
        swap( &a[ left ], &a[ right ] );
    if( a[ Center ] > a[ right ] )
        swap( &a[ Center ], &a[ right ] );

    swap( &a[ Center ], &a[ right - 1 ] );  
    return a[ right - 1 ];                
}
void insert_sort( int a[ ], int n )
{
    int j, p, tmp; 
    for( p = 1; p < n; p++ )
    {
        tmp = a[ p ];
        for( j = p; j > 0 && a[ j - 1 ] > tmp; j-- )
            a[ j ] = a[ j - 1 ];
        a[ j ] = tmp;
    }
}

void q_select( int a[ ], int k, int left, int right )
{
    int i, j;
    int Pivot;

    if( left + Cutoff <= right )
    {
        Pivot = median3( a, left, right );
        //取三数中值作为枢纽元，可以消除最坏情况而保证此算法是O（N）
        i = left; j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < Pivot ){ }
            while( a[ --j ] > Pivot ){ }
            if( i < j )
                swap( &a[ i ], &a[ j ] );
            else
                break;
        }
        swap( &a[ i ], &a[ right - 1 ] );  /* 重置枢纽元 */

        if( k <= i )
            q_select( a, k, left, i - 1 );
        else if( k > i + 1 )
            q_select( a, k, i + 1, right );
    }
    else  
        insert_sort( a + left, right - left + 1 );
}

int main(int argc, const char *argv[])
{
    int a[] = {0,2,1,3,4};
    int k = 2;
    q_select(a,k,0,5);
    printf("%d\n",a[k-1]);
    return 0;
}
