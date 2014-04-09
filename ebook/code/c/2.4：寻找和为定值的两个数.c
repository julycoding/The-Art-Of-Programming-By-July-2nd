//解法五
//代码一
//O（N）
Pair findSum(int *s, int n, int x)
{
	//sort(s, s+n);   如果数组非有序的，那就事先排好序O(N log N)

	int *begin = s;
	int *end = s+n-1;

	while(begin < end)    //俩头夹逼，或称两个指针两端扫描法，很经典的方法，O(N)
	{
		if(*begin + *end > x)
		{
			--end;
		}
		else if(*begin + *end < x)
		{
			++begin;
		}
		else
		{
			return Pair(*begin, *end);
		}
	}

	return Pair(-1, -1);
}

//或者如下编写，
//代码二
//copyright@ zhedahht && yansha
//July、updated，2011.05.14。
bool find_num(int data[], unsigned int length, int sum, int& first_num, int& second_num)
{
	if(length < 1)
		return false;

	int begin = 0;
	int end = length - 1;

	while(end > begin)
	{
		long current_sum = data[begin] + data[end];

		if(current_sum == sum)
		{
			first_num = data[begin];
			second_num = data[end];
			return true;
		}
		else if(current_sum > sum)
			end--;
		else
			begin++;
	}
	return false;
}


//问题扩展
//算法所操作的区间,是左闭右开区间,还是左闭右闭区间,这个区间,需要在循环初始化,
//循环体是否终止的判断中,以及每次修改left,right区间值这三个地方保持一致,否则就可能出错.

//二分查找实现一
int search(int array[], int n, int v)
{
	int left, right, middle;

	left = 0, right = n - 1;

	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (array[middle] > v)
		{
			right = middle - 1;
		}
		else if (array[middle] < v)
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}

//二分查找实现二
int search(int array[], int n, int v)
{
	int left, right, middle;

	left = 0, right = n;

	while (left < right)
	{
		middle = left + (right - left) / 2;

		if (array[middle] > v)
		{
			right = middle;
		}
		else if (array[middle] < v)
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}
