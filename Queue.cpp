#include "Queue.h"

void Queue::Enqueue(int value) {
	list.PushFront(value);
}
int Queue::Dequeue() {
	return list.PopBack();
}
int Queue::Peek() {
	return list.PeekBack();
}
void Queue::Delete() {
	list.Delete();

}