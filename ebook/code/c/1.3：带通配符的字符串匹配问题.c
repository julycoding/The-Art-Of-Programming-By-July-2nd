//解法一
//copyright@cao_peng 2013/4/23
int str_len(char *a)
{
	//字符串长度
	if (a == 0)
	{
		return 0;
	}
	char *t = a;
	for (; *t; ++t)
		;
	return (int) (t - a);
}

void str_copy(char *a, const char *b, int len)
{
	//拷贝字符串 a = b
	for (; len > 0; --len, ++b, ++a)
	{
		*a = *b;
	}
	*a = 0;
}

char *str_join(char *a, const char *b, int lenb)
{
	//连接字符串 第一个字符串被回收
	char *t;
	if (a == 0)
	{
		t = (char *) malloc(sizeof(char) * (lenb + 1));
		str_copy(t, b, lenb);
		return t;
	}
	else
	{
		int lena = str_len(a);
		t = (char *) malloc(sizeof(char) * (lena + lenb + 2));
		str_copy(t, a, lena);
		*(t + lena) = ' ';
		str_copy(t + lena + 1, b, lenb);
		free(a);
		return t;
	}
}

int canMatch(char *input, char *rule)
{
	// 返回最长匹配长度 -1表示不匹配
	if (*rule == 0)
	{
		//已经到rule尾端
		return 0;
	}
	int r = -1 , may;
	if (*rule == '*')
	{
		r = canMatch(input, rule + 1);  // *匹配0个字符
		if (*input)
		{
			may = canMatch(input + 1, rule);  // *匹配非0个字符
			if ((may >= 0) && (++may > r))
			{
				r = may;
			}
		}
	}
	if (*input == 0)
	{
		//到尾端
		return r;
	}
	if ((*rule == '?') || (*rule == *input))
	{
		may = canMatch(input + 1, rule + 1);
		if ((may >= 0) && (++may > r))
		{
			r = may;
		}
	}
	return r;
}

char * my_find(char input[], char rule[])
{
	int len = str_len(input);
	int *match = (int *) malloc(sizeof(int) * len);  //input第i位最多能匹配多少位 匹配不上是-1
	int i, max_pos = - 1;
	char *output = 0;

	for (i = 0; i < len; ++i)
	{
		match[i] = canMatch(input + i, rule);
		if ((max_pos < 0) || (match[i] > match[max_pos]))
		{
			max_pos = i;
		}
	}
	if ((max_pos < 0) || (match[max_pos] <= 0))
	{
		//不匹配
		output = (char *) malloc(sizeof(char));
		*output = 0;   // \0
		return output;
	}
	for (i = 0; i < len;)
	{
		if (match[i] == match[max_pos])
		{
			//找到匹配
			output = str_join(output, input + i, match[i]);
			i += match[i];
		}
		else
		{
			++i;
		}
	}
	free(match);
	return output;
}


//解法二
//copyright@chpeih 2013/4/23
char* my_find(char input[], char rule[])
{
	//write your code here
	int len1, len2;
	for (len1 = 0; input[len1]; len1++);
	for (len2 = 0; rule[len2]; len2++);
	int MAXN = len1 > len2 ? (len1 + 1) : (len2 + 1);
	int  **dp;

	//dp[i][j]表示字符串1和字符串2分别以i j结尾匹配的最大长度
	//记录dp[i][j]是由之前那个节点推算过来  i*MAXN+j
	dp = new int *[len1 + 1];
	for (int i = 0; i <= len1; i++)
	{
		dp[i] = new int[len2 + 1];

	}

	dp[0][0] = 0;
	for (int i = 1; i <= len2; i++)
		dp[0][i] = -1;
	for (int i = 1; i <= len1; i++)
		dp[i][0] = 0;

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (rule[j - 1] == '*')
			{
				dp[i][j] = -1;
				if (dp[i - 1][j - 1] != -1)
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;

				}
				if (dp[i - 1][j] != -1 && dp[i][j] < dp[i - 1][j] + 1)
				{
					dp[i][j] = dp[i - 1][j] + 1;
				}
			}
			else if (rule[j - 1] == '?')
			{
				if (dp[i - 1][j - 1] != -1)
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;

				}
				else dp[i][j] = -1;
			}
			else
			{
				if (dp[i - 1][j - 1] != -1 && input[i - 1] == rule[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else dp[i][j] = -1;
			}
		}
	}

	int m = -1;//记录最大字符串长度
	int *ans = new int[len1];
	int count_ans = 0;//记录答案个数
	char *returnans = new char[len1 + 1];
	int count = 0;
	for (int i = 1; i <= len1; i++)
		if (dp[i][len2] > m)
		{
			m = dp[i][len2];
			count_ans = 0;
			ans[count_ans++] = i - m;
		}
		else if (dp[i][len2] != -1 && dp[i][len2] == m)
		{
			ans[count_ans++] = i - m;
		}

		if (count_ans != 0)
		{
			int len = ans[0];
			for (int i = 0; i < m; i++)
			{
				printf("%c", input[i + ans[0]]);
				returnans[count++] = input[i + ans[0]];
			}
			for (int j = 1; j < count_ans; j++)
			{
				printf(" ");
				returnans[count++] = ' ';
				len = ans[j];
				for (int i = 0; i < m; i++)
				{
					printf("%c", input[i + ans[j]]);
					returnans[count++] = input[i + ans[j]];
				}
			}
			printf("\n");
			returnans[count++] = '\0';
		}

		return returnans;
}
