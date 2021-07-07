#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* next;

	Node(T value, Node<T>* next) {
		this->value = value;
		this->next = next;
	}
};

template <typename T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;

	int size;

public:
	Queue() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~Queue() {
		while (head) {
			Node<T>* n = head;
			head = head->next;
			delete n;
		}
	}

	void push(T value) {
		Node<T>* n = new Node<T>(value, nullptr);
		if (size == 0) {
			head = n;
		}
		else {
			tail->next = n;
		}
		tail = n;
		size++;
	}

	void pop() {
		if (size != 0) {
			Node<T>* n = head;
			head = head->next;
			delete n;

			size--;
		}
	}

	T peek() {
		return head->value;
	}

	bool isEmpty() {
		return size == 0;
	}

};

//int main() {
//
//	return 0;
//}