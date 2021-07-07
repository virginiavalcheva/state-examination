#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int v) {
		value = v;
		next = nullptr;
	}
};

Node* sort(Node* node) {
	Node* result = node;
	Node* curr = result;
	Node* next = result->next;
	while (curr && next) {
		while (next) {
			if (curr->value >= next->value) {
				int currentVal = curr->value;
				curr->value = next->value;
				next->value = currentVal;
			}
			next = next->next;
		}
		curr = curr->next;
		next = curr->next;
	}
	return result;
}

//int main() {
//	Node* first = new Node(2);
//	first->next = new Node(3);
//	first->next->next = new Node(1);
//	first->next->next->next = new Node(8);
//	first->next->next->next->next = new Node(22);
//	first->next->next->next->next->next = new Node(0);
//
//	Node* res = sort(first);
//
//	while (res) {
//		cout << res->value << " ";
//		res = res->next;
//	}
//}