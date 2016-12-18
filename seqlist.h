#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __SEQLIST__
#define __SEQLIST__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define MAX_SIZE 10

typedef int  datatype;
typedef struct Seqlist
{
	datatype arr[MAX_SIZE];//��ű�����ݣ�
	size_t size;//���ݵĸ�����
}Seqlist;

void Init(Seqlist* seq);//��ʼ����
void PrintSeqlist(Seqlist *seq);//��ӡ˳���
//ʵ����ɾ�Ĳ飻
void  Pushback(Seqlist *seq, datatype x);
void Popback(Seqlist *seq, datatype x);
void PushFront(Seqlist *seq, datatype x);
void PopFront(Seqlist *seq, datatype x);
void Insert(Seqlist *seq, datatype x, size_t pos);
int Find(Seqlist *seq, datatype x);
void Erase(Seqlist *seq, size_t pos);
void Remove(Seqlist *seq, datatype x);
void Removall(Seqlist *seq, datatype x);
void BubbleSort(Seqlist *seq);
void SelsectSort(Seqlist *seq);
void InsertSort(Seqlist *seq);
int BinarySearch(Seqlist *seq, datatype x);
void exit(Seqlist *seq);
#endif 