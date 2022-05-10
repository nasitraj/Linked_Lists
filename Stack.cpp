#include "Stack.h"

void Stack::Push(int value) {
	list.PushFront(value);
}
int Stack::Pop() {
	return list.Popfront();
}
int Stack::Peek() {
	return list.PeekFront();
}
void Stack::Delete() {
	list.Delete();
}