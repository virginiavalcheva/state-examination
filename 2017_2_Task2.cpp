#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int val, Node* n) {
		this->value = val;
		this->next = n;
	}
};

struct NodeList {
	Node* node;
	NodeList* next;

	NodeList(Node* node, NodeList* next) {
		this->node = node;
		this->next = next;
	}
};

bool isSorted(Node* node) {
	while (node->next) {
		if (node->value > node->next->value) {
			return false;
		}
		node = node->next;
	} 
	return true;
}

Node* sortList(NodeList* lists) {

	Node* result = nullptr; 

	while (lists) {

		Node* currentList = lists->node;

		if (isSorted(currentList)) {

			Node* currentNode = currentList;

			while (currentNode) {
				int currentValue = currentNode->value;
				
				if (result == nullptr) {
					result = new Node(currentValue, nullptr);
					
				} 
				else {
					Node* res = result;

					while (res) {
						if (res->value <= currentValue && (res->next == nullptr || res->next->value >= currentValue)) {
							Node* next = res->next;
							res->next = new Node(currentValue, next);
							break;
						} 
						res = res->next;
					}
				}

				currentNode = currentNode->next;
			}
		}
		lists = lists->next;
	}

	return result;
}



//int main() {
//	Node* arr1[] = {
//		new Node(8, nullptr), //0
//		new Node(7, arr1[0]), //1
//		new Node(5, arr1[1]), //2
//		new Node(2, arr1[2]), //3
//		new Node(1, arr1[3]) //4
//	};
//
//	Node* list1 = arr1[4];
//
//	Node* arr2[] = {
//		new Node(8, nullptr),
//		new Node(6, arr2[0]),
//		new Node(4, arr2[1]),
//		new Node(2, arr2[2]),
//		new Node(1, arr2[3])
//	};
//
//	Node* list2 = arr2[4];
//
//	Node* arr3[] = {
//		new Node(9, nullptr),
//		new Node(2, arr3[0]),
//		new Node(4, arr3[1]),
//		new Node(6, arr3[2]),
//		new Node(10, arr3[3])
//	};
//
//	Node* list3 = arr3[4];
//
//	NodeList* listsArr[] = {
//		new NodeList(list1, nullptr),
//		new NodeList(list2, listsArr[0]),
//		new NodeList(list3, listsArr[1])
//	};
//
//	NodeList* lists = listsArr[2];
//
//	Node* result = sortList(lists);
//
//	while (result) {
//		cout << result->value << " ";
//		result = result->next;
//	}
//
//}