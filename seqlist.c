#include "seqlist.h"

//初始化
void Init(Seqlist *seq)
{
	assert(seq);

	seq->size= 0;//顺序表的初始化；
	memset(seq, 0, sizeof(datatype)*MAX_SIZE);
}
//打印
void PrintSeqlist(Seqlist *seq)
{
	assert(seq);

	int i = 0;
	for (; i < seq->size; i++)
	{
		printf(" %d ", seq->arr[i]);
	}
	printf("\n");
}
//尾插
void  Pushback(Seqlist *seq, datatype x)
{
	assert(seq);

	if (seq->size == MAX_SIZE)
	{
		printf("list is full\n");
		exit(0);
	}
	seq->arr[seq->size] = x;
	seq->size++;
}
//尾删
void Popback(Seqlist *seq, datatype x)
{
	assert(seq);
	//空表
	//不为空
	if (seq->size == 0)
	{
		printf("list is empty\n");
		exit(0);
	}
	seq->size--;
}
//头插
void PushFront(Seqlist*seq, datatype x)
{
	assert(seq);

	if (seq->size == MAX_SIZE)//表满；
	{
		printf("list is full\n");
		exit(0);
	}

	int i = 0;
	for (i = seq->size; i >= 0;i--)
	{
		seq->arr[i] = seq->arr[i-1];
	}
	seq->arr[0] = x;
	seq->size++;
}
//头删
void PopFront(Seqlist *seq, datatype x)
{
	assert(seq);

	if (seq->size == 0)
	{
		printf("list is enpty\n");
		exit(0);
	}

	int i = 0;
	for (i = 0; i < seq->size;i++)
	{
		seq->arr[i] = seq->arr[i+1];
	}
	seq->size--;
}

//插入
void Insert(Seqlist *seq, datatype x, size_t pos)
{
	assert(seq);

	if (seq->size == MAX_SIZE || (pos<1 && pos > MAX_SIZE+1))
	{
		printf("list is full\n");
		exit(0);
	}

	int i = 0;
	for (i = seq->size-1; i >= pos; i--)
	{
		seq->arr[i+1] = seq->arr[i];
	}
	seq->arr[pos] = x;
	seq->size++;
}
//查找
int Find(Seqlist *seq, datatype x)
{

	assert(seq);

	if (seq->size == 0)
	{
		printf("list is empty\n");
		exit(0);
	}

	int i = 0;
	for (; i < seq->size; i++)
	{
		if (seq->arr[i] == x)
		{
			printf(" found  %d\n",x);
			return i;
		}
	}
	return -1;
}

//删除指定位置的元素；
void Erase(Seqlist *seq, size_t pos)
{
	assert(seq);

	if (seq->size == 0)
	{
		printf("list is empty\n");
		exit(0);
	}

	int i = 0;
	for (i= pos; i < seq->size; i++)
	{
		seq->arr[i] = seq->arr[i + 1];
	}
	seq->size--;
}

//删出单个元素
void Remove(Seqlist *seq, datatype x)
{
	assert(seq);

	if (seq->size == 0)
	{
		printf("list is empty\n");
		exit(0);
	}
	int i = 0;
	for (i = 0; i < seq->size;i++)
	{
		if (seq->arr[i] == x)
		{
			break;
		}
	}
	if (i == seq->size)
	{
		printf("删除的元素不存在\n");
		exit(0);
	}
	int j = 0;
	for (j = i + 1; j < seq->size; j++)
	{
		seq->arr[j - 1] = seq->arr[j];
	}
	seq->size--;
}
//删除出现相同的元素
void Removall(Seqlist *seq, datatype x)
{
	assert(seq);

	if (seq->size == 0)
	{
		printf("list is full");
		exit(0);
	}

	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		if (x == seq->arr[i])
		{
			int j = 0;
			for (j = i; j < seq->size - 1; j++)
			{
				seq->arr[j] = seq->arr[j + 1];
			}
			seq->size--;
			i--;
		}
	}
}
//冒泡排序
void BubbleSort(Seqlist *seq)
{
	assert(seq);

	int i = 0;
	int flag = 1;
	for (; i < seq->size; i++)
	{
		int j = 0;
		flag = 0;
		for (j = 0; j < seq->size - i - 1; j++)
		{
			if (seq->arr[j]>seq->arr[j+1])
			{
				int tmp = seq->arr[j];
				seq->arr[j] = seq->arr[j + 1];
				seq->arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag != 1)
		{
			break;
		}
	}
}
//选择排序
void SelsectSort(Seqlist *seq)
{
	assert(seq);

	int i = 0;
	for (i = 0; i < seq->size-1; i++)
	{
		int min =i;
		int j = 0;
		for (j = i+1; j < seq->size; j++)
		{
			if ((seq->arr[min]) >(seq->arr[j]))
			{
				min = j;
			}
		}

		if (seq->arr[min] != seq->arr[i])
		{
			int tmp = seq->arr[i];
			seq->arr[i] = seq->arr[min];
			seq->arr[min] = tmp;
		}
	}
}
//插入排序
void InsertSort(Seqlist *seq)
{
		assert(seq);
		
			int i = 0;
			for (i = 1; i < seq->size; i++)
			{
			   int tmp = seq->arr[i];
			   int j = 0;
			   for (j = i - 1; j >= 0; j--)
			   {
				   if (seq->arr[j]>tmp)
				   {
		
					   seq->arr[j + 1] = seq->arr[j];
				   }
				   else
				   {
					   break;
				   }
			   }
			   seq->arr[j+1] = tmp;
			}
}
//二分查找
int BinarySearch(Seqlist *seq, datatype x)
{
	assert(seq);

	int left = 0;
	int right = seq->size - 1;
	if (seq->size == 0)
	{
		printf("list is empty\n");
	}
	if (left > right)
	{
		return;
	}
	while (left <= right)
	{
		int mid = left + ((left + right) >> 1);
		if (seq->arr[mid] == x)
		{
			printf("找到了%d\n",x);
			break;
		}
		  else if (seq->arr[mid] < x)
		  {
			left = mid + 1;
		  }
		  else 
		   {
			right = mid - 1;
		   }
	}
}
//尾插尾删测试
void test1()
{
	Seqlist seq;
	Init(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 2);
	Pushback(&seq, 3);
	Pushback(&seq, 4);
	Popback(&seq, 3);
	Popback(&seq, 4);
	PrintSeqlist(&seq);
}
//头插头删测试
void test2()
{
	Seqlist seq;
	Init(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 5);
	PushFront(&seq, 6);
	PopFront(&seq, 6);
	PopFront(&seq, 5);
	PrintSeqlist(&seq);
}
//插入删除测试
void test3()
{
	Seqlist seq;
	Init(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 3);
	Pushback(&seq, 4);
	Insert(&seq,2,2);
	PrintSeqlist(&seq);
	Erase(&seq, 4);
	PrintSeqlist(&seq);
}
//测试删除给定的某个元素，删除几个相同元素
void test4()
{
	Seqlist seq;
	Init(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 2);
	Pushback(&seq, 2);
	Pushback(&seq, 2);
	Pushback(&seq, 3);
	Pushback(&seq, 4);
	PrintSeqlist(&seq);
	Remove(&seq, 4);
	PrintSeqlist(&seq);
	Removall(&seq, 2);
	PrintSeqlist(&seq);
}
//测试几种排序
void test5()
{
	Seqlist seq;
	Init(&seq);
	Pushback(&seq, 5);
	Pushback(&seq, 2);
	Pushback(&seq, 4);
	Pushback(&seq, 3);
	Pushback(&seq, 1);
	PrintSeqlist(&seq);
	BubbleSort(&seq);
	PrintSeqlist(&seq);
	Pushback(&seq, 4);
	Pushback(&seq, 3);
	SelsectSort(&seq);
	PrintSeqlist(&seq);
	InsertSort(&seq);
	PrintSeqlist(&seq);
}
//测试折半查找
void test6()
{
	Seqlist seq;
	Init(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 2);
	Pushback(&seq, 3);
	Pushback(&seq, 4);;
	BinarySearch(&seq, 1);
	PrintSeqlist(&seq);
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	system("pause");
	return 0;
}