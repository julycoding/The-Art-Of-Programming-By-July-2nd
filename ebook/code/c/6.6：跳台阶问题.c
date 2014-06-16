//解法一
long long Fibonacci_Solution1(unsigned int n)
{
	int result[2] = {0, 1, 2};
	if (n <= 2)
		return result[n];

	return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}
