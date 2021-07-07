#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class Node {
public:
	int num;
	Node* next;
	Node* nextK;

	Node(int num, Node* next, Node* nextK) {
		this->num = num;
		this->next = next;
		this->nextK = nextK;
	}

	int getNum() {
		return num;
	}
};

int getNumber(string str, int start, int end) {
	int number = 0;
	int x = 0;
	for (int i = end; i >= start; i--) {
		int currentNum = str[i] - '0';
		number += currentNum * pow(10, x);
		x++;
	}
	return number;
}

int getCountOfNumbers(string line) {
	int size = 0;
	for (int i = 0; i <= line.length(); i++) {
		char ch = line[i];
		if (ch == ' ' || i == line.length()) {
			size++;
		}
	}
	return size;
}

int* getArrayOfNumbers(string line, int size) {
	int* arr = new int[size];
	int j = 0;

	int startIndex = 0;
	for (int i = 0; i <= line.length(); i++) {
		char ch = line[i];
		if (ch == ' ' || i == line.length()) {
			arr[j] = getNumber(line, startIndex, i - 1);
			j++;
			startIndex = i + 1;
		}
	}
	return arr;
}

Node* constructList(int* arr, int size, int k) {
	Node* prev = nullptr;
	Node* prevK = nullptr;
	Node* first = nullptr;

	for (int i = 0; i < size; i++) {
		Node* node = new Node(arr[i], nullptr, nullptr);
		if (first == nullptr) {
			first = node;
		}
		if (i % k == 0) {
			if (prevK) {
				prevK->nextK = node;
			}
			prevK = node;
		}
		if (prev) {
			prev->next = node;
		}
		prev = node;
	}
	return first;
}

bool member(Node* node, int k) {
	cout << node->getNum() << endl;
	if (node == nullptr) {
		return false;
	}
	if (node->getNum() == k) {
		return true;
	}
	if (node->nextK != nullptr && node->nextK->getNum() <= k) {
		member(node->nextK, k);
	}
	else {
		member(node->next, k);
	}
}

//int main() {
//	ifstream file("C:\\Users\\virv\\OneDrive - Software AG\\Desktop\\file.txt");
//	string line;
//	getline(file, line);
//	file.close();
//
//	int size = getCountOfNumbers(line);
//
//	int* arr = getArrayOfNumbers(line, size);
//
//	int k = ceil(sqrt(size));
//	Node* list = constructList(arr, size, k);
//	//
//	//while (list) {
//	//	cout << list->getNum() << " ";
//
//	//	if (list->nextK) {
//	//		cout << "has next ";
//	//		cout << list->nextK->getNum() << " ";
//	//	}
//	//	cout << endl;
//	//	list = list->next;
//	//}
//	//cout << endl;
//	cout << "List has 6 -> " << member(list, 6);
//}