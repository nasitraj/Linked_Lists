#pragma once
#include "List.h"

class Stack
{
	List list;

public:
	void Push(int value);
	int Pop();
	int Peek();
	void Delete();
};

