#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
struct Node {
	T value;
	vector<Node*> children;

	Node(T value) {
		this->value = value;
	}

	void addChild(Node<T>* node) {
		children.push_back(node);
	}
};

template <typename T>
void bfs(Node<T>* root) {
	queue<Node<T>*> qu;
	qu.push(root);

	while (!qu.empty()) {
		int size = qu.size();
		for (int i = 0; i < size; i++) {
			Node<T>* n = qu.front();
			qu.pop(); 
			cout << n->value << " ";
			for (Node<T>* child : n->children) {
				qu.push(child);
			}
		}
		cout << endl;
	}
}

template <typename T>
void dfs(Node<T>* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->value << " ";
	for (Node<T>* child : root->children) {
		dfs(child);
	}
}

template <typename T>
int height(Node<T>* root) {
	if (root == nullptr) {
		return 0;
	}
	int depth = 0;
	for (Node<T>* child : root->children) {
		depth = max(height(child), depth);
	}
	return depth + 1;
}

template <typename T>
int countNodes(Node<T>* root) {
	if (root == nullptr) {
		return 0;
	}
	int sum = 0;
	for (Node<T>* child : root->children) {
		sum += countNodes(child);
	}
	return sum + 1;
}


//int main() {
//
//	Node<int>* root = new Node<int>(1);
//	Node<int>* n1 = new Node<int>(2);
//	Node<int>* n2 = new Node<int>(3);
//	Node<int>* n3 = new Node<int>(4);
//	Node<int>* n4 = new Node<int>(5);
//	Node<int>* n5 = new Node<int>(6);
//	Node<int>* n6 = new Node<int>(7);
//	Node<int>* n7 = new Node<int>(8);
//	Node<int>* n8 = new Node<int>(9);
//
//	root->addChild(n1);
//	root->addChild(n2);
//	n1->addChild(n3);
//	n1->addChild(n4);
//	root->addChild(n5);
//	root->addChild(n6);
//	n5->addChild(n7);
//	n7->addChild(n8);
//	
//	bfs(root);
//
//	cout << endl;
//
//	dfs(root);
//
//	cout << "\nHeight ";
//
//	cout << height(root);
//
//	cout << "\nCount of nodes ";
//
//	cout << countNodes(root);
//
//	cout << endl;
//
//	return 0;
//}