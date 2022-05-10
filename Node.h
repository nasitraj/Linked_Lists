#pragma once
class Node
{
public:
	Node* next;
	int data;
	Node* previous;

	Node(int value = 0);
};

