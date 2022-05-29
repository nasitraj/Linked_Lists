#include "HashTable.h"


bool HashTable::isEmpty() {
	int sum = 0;
	for (int i = 0; i < hasGroup; i++) {
		sum += table[i].size();
	}
	if (!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key) {
	return key % hasGroup;
}

void HashTable::insert(int key, string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExist = false;
	auto end1 = end(cell);
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExist = true;
			bItr->second = value;
			printf("Warning!! Value has be replace\n");
			break;
		}

	}

	if (!keyExist) {
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::remove(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExist = false;

	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExist = true;
			bItr = cell.erase(bItr);
			cout << "Warning!! Key exists. Item Removed." << endl;
			break;
		}
	}

	if (!keyExist) {
		cout << "Warning!! Item not found" << endl;
	}
	return;
}

void HashTable::printTable() {
	for (int i = 0; i < hasGroup; i++) {
		if (table[i].size() == 0) 
			continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Info Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}