#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
int num;
typedef struct node
{
	char name[20];
	char tele[20];
	struct node* next;
}node;
void ADD(node** phead);
void DELE(node** phead);
node* get(node**phead);
void SEAR(node** phead);
void UPDATE(node** phead);
void SHOW(node** phead);
void init(node**phead);
//void savecon(node** phead);