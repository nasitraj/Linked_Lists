#pragma once
#include "Node.h"

class List
{
	Node* head;
	Node* tail;

public:
	List();
	~List();
	void Display();
	int Length();
	void Delete();

	void PushFront(int value);
	int Popfront();
	int PeekFront();

	void PushBack(int value);
	int PopBack();
	int PeekBack();

	int PopatIndex(int value);
	void SwitchwithPrevious(Node* n);
	int SearchLinear(int value);

	void SortSelection();
	void SortInsertion();
};

