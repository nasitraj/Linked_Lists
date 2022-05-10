#include "List.h"
#include <iostream>

using namespace std;

List::List() {
	head = nullptr;
	tail = nullptr;
}

List::~List() {
	Delete();
}

void List::Display() {
	cout << "List: ";
	if (head == nullptr)
		cout << "....";
	else {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data;
			temp = temp->next;
			if (temp != nullptr) {
				cout << " , ";
			}
		}
	}
	cout << endl;
}

int List::Length() {
	int count = 0;
	Node* temp = head;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

void List::Delete() {
	if (head != nullptr) {
		Node* temp = head->next;
		Node* previous = head;
		delete previous;
		while (temp != nullptr) {
			previous = temp;
			temp = temp->next;
			delete previous;
		}
		head = nullptr;
		tail = nullptr;
	}
}

void List::PushFront(int value) {
	Node* temp = new Node(value);

	if (head == nullptr) {
		tail = temp;
	}
	else {
		temp->next = head;
		head->previous = temp;
	}
	head = temp;
}

int List::Popfront() {
	Node* next = head->next;
	int data = head->data;
	if (tail == head) {
		tail = nullptr;
	}
	delete head;
	head = next;
	return data;
}

int List::PeekFront() {
	return head->data;
}

void List::PushBack(int value) {
	Node* temp = new Node(value);

	if (head == nullptr) {
		head = temp;
	}
	else {
		tail->next = temp;
		temp->previous = tail;
	}
	tail = temp;
}

int List::PopBack() {
	if (head == tail)
		return Popfront();

	Node* temp = tail->previous;
	int data;
	data = tail->data;
	delete tail;
	tail = temp;
	temp->next = nullptr;


	return data;
}

int List::PeekBack() {
	return tail->data;
}


int List::PopatIndex(int value) {
	Node* n = head;
	int index = 0;

	while (index != value) {
		n = n->next;
		index++;
	}
	int data = n->data;

	if (n->previous == nullptr)
		head = n->next;
	else
		n->previous->next = n->next;

	if (n->next == nullptr)
		tail = n->previous;
	else
		n->next->previous = n->previous;

	delete n;
	return data;
}

void List::SwitchwithPrevious(Node* n) {
	if (n != nullptr && n->previous != nullptr) {
		Node* one = n->previous->previous;
		Node* two = n->previous;
		Node* three = n;
		Node* four = n->next;

		three->previous = one;

		if (one != nullptr)
			one->next = three;
		else
			head = three;

		three->next = two;
		two->previous = three;

		two->next = four;
		if (four != nullptr)
			four->previous = two;
		else
			tail = two;
	}
}

int List::SearchLinear(int value) {
	Node* n = head;
	int index = 0;

	while (n != nullptr) {
		if (n->data == value) {
			return index;
		}
		n = n->next;
		index++;
	}
	return -1;
}

void List::SortSelection() {
	if (head != nullptr && head != tail) {
		List* sorted = new List;
		Node* n = head;
		int minValue, minIndex, index;

		while (head != nullptr) {
			minValue = n->data;
			minIndex = 0;
			index = 0;

			while (n != nullptr) {
				if (n->data < minValue) {
					minValue = n->data;
					minIndex = index;
				}
				index++;
				n = n->next;
			}
			sorted->PushBack(PopatIndex(minIndex));
			n = head;
		}

		head = sorted->head;
		tail = sorted->tail;
		sorted->head = nullptr;
		sorted->tail = nullptr;
		delete sorted;

	}
}
void List::SortInsertion() {
	if (head != nullptr && head->next != nullptr) {
		Node* index = head->next;

		while (index != nullptr) {
			Node* n = index;
			while (n->previous != nullptr) {
				if (n->data < n->previous->data)
					SwitchwithPrevious(n);
				else
					break;
			}
			index = index->next;
		}

	}
}