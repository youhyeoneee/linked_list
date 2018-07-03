#pragma once

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<iostream>
#include<fstream>
using namespace std;


/***********************
* List에 관련된 struct *
************************/


// list의 int형 노드. 실제 데이터는 각 노드에 저장된다.
struct Node
{
	int val;
	Node* next;
};

// list 본체. head는 항상 첫번째 노드를 가리키고 있다.
struct List
{
	Node* head = nullptr;
	int length = 0;
};


/************************
* List에 사용되는 함수들 *
*************************/

// 빈 list를 만든다. head는 빈 노드.
void make_list(List& list);

// list의 현재 길이를 리턴한다.
int length(List& list);

// list의 맨 뒤에 노드를 추가한다.
void insert(List& list, int data);


// list에서 data와 일치하는 노드를 삭제하고 true를 리턴한다.
// 만약 일치하는 노드가 없으면 false를 리턴한다.
bool remove(List& list, int data);

// list에서 해당 위치의 노드를 삭제하고 true를 리턴한다.
// 만약 pos가 list의 길이를 넘어간다면 false를 리턴한다.
bool remove_at(List& list, int pos);

// list의 데이터를 앞에서부터 출력한다.
void print_all(List& list);

#endif _LINKED_LIST_H