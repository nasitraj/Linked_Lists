#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
	Stack stack;
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);
	cout << stack.Pop() << " , ";
	cout << stack.Peek() << " , ";
	cout << stack.Pop() << " , ";
	cout << stack.Pop() << endl;

	Queue queue;
	queue.Enqueue(5);
	queue.Enqueue(6);
	queue.Enqueue(7);
	cout << queue.Dequeue() << " , ";
	cout << queue.Peek() << " , ";
	cout << queue.Dequeue() << " , ";
	cout << queue.Dequeue() << endl;
	

	List list;
	list.PushBack(6);
	list.PushBack(7);
	list.PushBack(8);
	list.PushFront(9);
	list.Display();

	cout << "Lenght: " << list.Length() << endl;

	list.Popfront();
	list.Display();
	cout << "Lenght: " << list.Length() << endl;
	list.PopBack();
	list.Display();
	cout << "Lenght: " << list.Length() << endl;

	cout << list.PeekFront() << endl;
	cout << list.PeekBack() << endl;

	list.Display();
	list.Delete();
	list.Display();
	list.Delete();
	list.Display();
	list.Delete();


	srand(time(NULL));

	List sortedlist;

	for (int i = 0; i < 100; i++) {
		int x = rand() % 100;
		sortedlist.PushBack(x);
	}
	sortedlist.Display();


	cout << endl << sortedlist.PopatIndex(1) << endl << endl;
	sortedlist.Display();
	cout << endl;

	int find = sortedlist.SearchLinear(44);
	if (find == -1)
		cout << "44 is not in the list" << endl << endl;
	else
		cout << "44 is at " << find << "." << endl << endl;

	//list.SortSelection();
	sortedlist.SortInsertion();
	sortedlist.Display();
}