#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// Hashtable to implement

class HashTable {
private:
	static const int hasGroup = 10;
	list<pair<int, string>> table[hasGroup];

public:
	bool isEmpty();
	int hashFunction(int key);
	void insert(int key, string value);
	void remove(int key);
	string searchTable(int key);
	void printTable();
};

