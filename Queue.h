#pragma once
#include "List.h"

class Queue
{
	List list;

public:
	void Enqueue(int value);
	int Dequeue();
	int Peek();
	void Delete();
};

