//copyright@yansha &&July
//July、updated，2011.05.08

//题目描述：
//搜索引擎会通过日志文件把用户每次检索使用的所有检索串都记录下来，每个查询串的
//长度为1-255字节。假设目前有一千万个记录（这些查询串的重复度比较高，虽然总数是1千万，但如果
//除去重复后，不超过3百万个。一个查询串的重复度越高，说明查询它的用户越多，也就是越热门），
//请你统计最热门的10个查询串，要求使用的内存不能超过1G。

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

#define HASHLEN 2807303
#define WORDLEN 30

// 结点指针
typedef struct node_no_space *ptr_no_space;
typedef struct node_has_space *ptr_has_space;
ptr_no_space head[HASHLEN];

struct node_no_space
{
	char *word;
	int count;
	ptr_no_space next;
};

struct node_has_space
{
	char word[WORDLEN];
	int count;
	ptr_has_space next;
};

// 最简单hash函数
int hash_function(char const *p)
{
	int value = 0;
	while (*p != '\0')
	{
		value = value * 31 + *p++;
		if (value > HASHLEN)
			value = value % HASHLEN;
	}
	return value;
}

// 添加单词到hash表
void append_word(char const *str)
{
	int index = hash_function(str);
	ptr_no_space p = head[index];
	while (p != NULL)
	{
		if (strcmp(str, p->word) == 0)
		{
			(p->count)++;
			return;
		}
		p = p->next;
	}

	// 新建一个结点
	ptr_no_space q = new node_no_space;
	q->count = 1;
	q->word = new char [strlen(str)+1];
	strcpy(q->word, str);
	q->next = head[index];
	head[index] = q;
}


// 将单词处理结果写入文件
void write_to_file()
{
	FILE *fp = fopen("result.txt", "w");
	assert(fp);

	int i = 0;
	while (i < HASHLEN)
	{
		for (ptr_no_space p = head[i]; p != NULL; p = p->next)
			fprintf(fp, "%s  %d\n", p->word, p->count);
		i++;
	}
	fclose(fp);
}

// 从上往下筛选，保持小根堆
void sift_down(node_has_space heap[], int i, int len)
{
	int min_index = -1;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left <= len && heap[left].count < heap[i].count)
		min_index = left;
	else
		min_index = i;

	if (right <= len && heap[right].count < heap[min_index].count)
		min_index = right;

	if (min_index != i)
	{
		// 交换结点元素
		swap(heap[i].count, heap[min_index].count);

		char buffer[WORDLEN];
		strcpy(buffer, heap[i].word);
		strcpy(heap[i].word, heap[min_index].word);
		strcpy(heap[min_index].word, buffer);

		sift_down(heap, min_index, len);
	}
}

// 建立小根堆
void build_min_heap(node_has_space heap[], int len)
{
	if (heap == NULL)
		return;

	int index = len / 2;
	for (int i = index; i >= 1; i--)
		sift_down(heap, i, len);
}

// 去除字符串前后符号
void handle_symbol(char *str, int n)
{
	while (str[n] < '0' || (str[n] > '9' && str[n] < 'A') || (str[n] > 'Z' && str[n] < 'a') || str[n] > 'z')
	{
		str[n] = '\0';
		n--;
	}

	while (str[0] < '0' || (str[0] > '9' && str[0] < 'A') || (str[0] > 'Z' && str[0] < 'a') || str[0] > 'z')
	{
		int i = 0;
		while (i < n)
		{
			str[i] = str[i+1];
			i++;
		}
		str[i] = '\0';
		n--;
	}
}

int main()
{
	char str[WORDLEN];
	for (int i = 0; i < HASHLEN; i++)
		head[i] = NULL;

	// 将字符串用hash函数转换成一个整数并统计出现频率
	FILE *fp_passage = fopen("string.txt", "r");
	assert(fp_passage);
	while (fscanf(fp_passage, "%s", str) != EOF)
	{
		int n = strlen(str) - 1;
		if (n > 0)
			handle_symbol(str, n);
		append_word(str);
	}
	fclose(fp_passage);

	// 将统计结果输入文件
	write_to_file();

	int n = 10;
	ptr_has_space heap = new node_has_space [n+1];

	int c;

	FILE *fp_word = fopen("result.txt", "r");
	assert(fp_word);
	for (int j = 1; j <= n; j++)
	{
		fscanf(fp_word, "%s %d", &str, &c);
		heap[j].count = c;
		strcpy(heap[j].word, str);
	}

	// 建立小根堆
	build_min_heap(heap, n);

	// 查找出现频率最大的10个单词
	while (fscanf(fp_word, "%s %d", &str, &c) != EOF)
	{
		if (c > heap[1].count)
		{
			heap[1].count = c;
			strcpy(heap[1].word, str);
			sift_down(heap, 1, n);
		}
	}
	fclose(fp_word);

	// 输出出现频率最大的单词
	for (int k = 1; k <= n; k++)
		cout << heap[k].count << " " << heap[k].word << endl;

	return 0;
}
