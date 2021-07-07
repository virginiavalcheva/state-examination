#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node* next;

	Node(T value, Node* next) {
		this->value = value;
		this->next = next;
	}
};

template <typename T>
class Stack {
private:
	Node<T>* top;

public:
	Stack() {
		top = nullptr;
	}

	~Stack() {
		while (top) {
			Node<T>* n = top;
			top = top->next;
			delete n;
		}
	}

	void push(T ch) {
		Node<T>* n = new Node(ch, top);
		top = n;
	}

	void pop() {
		if (!isEmpty()) {
			Node<T>* n = top;
			top = top->next;
			delete n;
		}
	}

	T peek() {
		return top->value;
	}

	bool isEmpty() {
		return top == nullptr;
	}
};


//int main() {
//
//	return 0;
//}