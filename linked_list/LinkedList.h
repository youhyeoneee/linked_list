#pragma once

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<iostream>
#include<fstream>
using namespace std;


/***********************
* List�� ���õ� struct *
************************/


// list�� int�� ���. ���� �����ʹ� �� ��忡 ����ȴ�.
struct Node
{
	int val;
	Node* next;
};

// list ��ü. head�� �׻� ù��° ��带 ����Ű�� �ִ�.
struct List
{
	Node* head = nullptr;
	int length = 0;
};


/************************
* List�� ���Ǵ� �Լ��� *
*************************/

// �� list�� �����. head�� �� ���.
void make_list(List& list);

// list�� ���� ���̸� �����Ѵ�.
int length(List& list);

// list�� �� �ڿ� ��带 �߰��Ѵ�.
void insert(List& list, int data);


// list���� data�� ��ġ�ϴ� ��带 �����ϰ� true�� �����Ѵ�.
// ���� ��ġ�ϴ� ��尡 ������ false�� �����Ѵ�.
bool remove(List& list, int data);

// list���� �ش� ��ġ�� ��带 �����ϰ� true�� �����Ѵ�.
// ���� pos�� list�� ���̸� �Ѿ�ٸ� false�� �����Ѵ�.
bool remove_at(List& list, int pos);

// list�� �����͸� �տ������� ����Ѵ�.
void print_all(List& list);

#endif _LINKED_LIST_H