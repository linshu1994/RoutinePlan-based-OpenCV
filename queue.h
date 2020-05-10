#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE, *PNODE;

typedef struct Queue
{
	PNODE front;  //��ͷָ��
	PNODE rear;   //��βָ��
}QUEUE, *PQUEUE;

PQUEUE create_queue();
bool empty(PQUEUE);
void en_queue(PQUEUE, int);
bool de_queue(PQUEUE, int *);
void destroy_queue(PQUEUE);
int traverse_queue_return(PQUEUE);
void traverse_queue(PQUEUE pS);



/*
����һ���ն��У���ͷָ��Ͷ�βָ�붼ָ��ͷ��㣬
ͷ����в�������ݣ�ֻ���ָ��
*/
PQUEUE create_queue()
{
	PQUEUE pS = (PQUEUE)malloc(sizeof(Queue));
	pS->front = (PNODE)malloc(sizeof(NODE));
	if (!pS || !pS->front)
	{
		printf("pS or front malloc failed!!");
		exit(-1);
	}
	else
	{
		pS->rear = pS->front;
		pS->front->pNext = NULL;
	}
	return pS;
}

/*
�ж϶����Ƿ�Ϊ��
*/
bool empty(PQUEUE pS)
{
	if (pS->front == pS->rear)
		return true;
	else
		return false;
}

/*
���Ӻ������Ӷ�β���ӣ���ͷָ�뱣�ֲ���
*/
void en_queue(PQUEUE pS, int e)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (!pNew)
	{
		printf("pNew malloc failed");
		exit(-1);
	}
	else
	{
		pNew->data = e;
		pNew->pNext = NULL;
		pS->rear->pNext = pNew;
		pS->rear = pNew;
	}
	return;
}

/*
���Ӻ������Ӷ�ͷ���ӣ���βָ�뱣�ֲ��䣬�������һ��Ԫ�س���ʱ��
��Ҫ�Զ�βָ�����¸�ֵ��ʹ��ָ��ͷ���
*/
bool de_queue(PQUEUE pS, int *pData)
{
	if (empty(pS))
		return false;
	else
	{
		PNODE p = pS->front->pNext;
		*pData = p->data;
		pS->front->pNext = p->pNext;

		//�����Ƕ���ͷԪ�س��ӵ����������һ������£�ɾ����ͷԪ��ʱ
		//�����޸�ͷ����е�ָ�룬�������������һ��Ԫ�ر�ɾ��ʱ��
		//����βָ��Ҳ��ʧ�ˣ������Զ�βָ�����¸�ֵ��ָ��ͷ��㣩��
		if (pS->rear == p)
			pS->rear = pS->front;
		free(p);
	}
	return true;
}

/*
�������У��Ӷ�ͷ���β����������е�Ԫ��
*/
void traverse_queue(PQUEUE pS)
{
	if (empty(pS))
		printf("there is no data in the queue!\n");
	else
	{
		PNODE pCurrent = pS->front->pNext;
		printf("Now datas int the queue are:\n");
		while (pCurrent)
		{
			printf("%d ", pCurrent->data);
			pCurrent = pCurrent->pNext;
		}
		printf("\n");
	}
	return;
}

/*
�������У����������ʽ���ض���ֵ
*/
int* traverse_queue_return(PQUEUE pS,int length)
{
	int* returnArr = new int[length];
	if (empty(pS))
		printf("there is no data in the queue!\n");
	else
	{
		PNODE pCurrent = pS->front->pNext;
		for(int i = 0;i < length ;i++)
		{
			returnArr[i] = int(pCurrent->data);
			pCurrent = pCurrent->pNext;
		}
		printf("\n");
	}
	return returnArr;
}

/*
���ٶ���,ͷ���Ҳ������,���Ҳ��pS�ڵ����٣�������ָ��Ϊ�գ����ⴹֱָ��Ĳ���
*/
void destroy_queue(PQUEUE pS)
{
	if (empty(pS))
		return;
	else
	{
		while (pS->front)
		{
			pS->rear = pS->front->pNext;
			free(pS->front);
			pS->front = pS->rear;
		}
	}
	free(pS);
	pS = 0;
	return;
}


#endif