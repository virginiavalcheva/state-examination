#include <iostream>
#include <queue>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node* left;
	Node* right;

	Node(T value, Node* left, Node* right) {
		this->value = value;
		this->left = left;
		this->right = right;
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
			cout << n->value << " ";
			qu.pop();
			if (n->left) qu.push(n->left);
			if (n->right) qu.push(n->right);
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
	dfs(root->left);
	dfs(root->right);
}

template <typename T>
int height(Node<T>* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if (leftHeight >= rightHeight) {
		return leftHeight + 1;
	}
	return rightHeight + 1;
}

template <typename T>
int countNodes(Node<T>* root) {
	if (root == nullptr) {
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}

//int main() {
//	Node<int>* arr[5] = {
//		new Node<int>(5, nullptr, nullptr), // 0
//		new Node<int>(4, nullptr, nullptr), // 1
//		new Node<int>(3, nullptr, nullptr), // 2
//		new Node<int>(2, arr[1], arr[0]), // 3
//		new Node<int>(1, arr[3], arr[2]) // 4
//	};
//
//	Node<int>* root = arr[4];
//
//	cout << "BFS" << endl;
//	bfs(root);
//
//	cout << "DFS" << endl;
//	dfs(root);
//
//	cout << "\nDepth of tree ";
//	cout << height(root);
//
//	cout << "\nCount of nodes ";
//	cout << countNodes(root);
//
//	cout << endl;
//
//	return 0;
//}