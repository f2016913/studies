#include "seqlist.h"

//��ʼ��
void Init(Seqlist *seq)
{
	assert(seq);

	seq->size= 0;//˳���ĳ�ʼ����
	memset(seq, 0, sizeof(datatype)*MAX_SIZE);
}
//��ӡ
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
//β��
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
//βɾ
void Popback(Seqlist *seq, datatype x)
{
	assert(seq);
	//�ձ�
	//��Ϊ��
	if (seq->size == 0)
	{
		printf("list is empty\n");
		exit(0);
	}
	seq->size--;
}
//ͷ��
void PushFront(Seqlist*seq, datatype x)
{
	assert(seq);

	if (seq->size == MAX_SIZE)//������
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
//ͷɾ
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

//����
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
//����
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

//ɾ��ָ��λ�õ�Ԫ�أ�
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

//ɾ������Ԫ��
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
		printf("ɾ����Ԫ�ز�����\n");
		exit(0);
	}
	int j = 0;
	for (j = i + 1; j < seq->size; j++)
	{
		seq->arr[j - 1] = seq->arr[j];
	}
	seq->size--;
}
//ɾ��������ͬ��Ԫ��
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
//ð������
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
//ѡ������
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
//��������
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
//���ֲ���
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
			printf("�ҵ���%d\n",x);
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
//β��βɾ����
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
//ͷ��ͷɾ����
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
//����ɾ������
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
//����ɾ��������ĳ��Ԫ�أ�ɾ��������ͬԪ��
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
//���Լ�������
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
//�����۰����
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