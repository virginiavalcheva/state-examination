#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int value;
	vector<Node*> children;

	Node(int value) {
		this->value = value;
	}

	void addChild(Node* child) {
		children.push_back(child);
	}

};

Node* buildTree(int arr[], int size, int k) {
	Node* root = new Node(arr[0]);

	queue<Node*> qu;
	qu.push(root);

	int j = 1;
	size--;
	while (size > 0) {

		Node* node = qu.front();
		qu.pop();

		for (int i = 0; i < k; i++) {
			if (size > 0) {
				Node* child = new Node(arr[j]);
				node->addChild(child);
				qu.push(child);
				j++;
				size--;
			}
		}
	}

	return root;
}

int getHeight(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	int depth = 0;
	for (Node* child : root->children) {
		depth = max(getHeight(child), depth);
	}
	return depth + 1;
}

void printTree(Node* tree) {
	
	queue<Node*> qu;
	qu.push(tree);
	cout << tree->value;
	cout << endl;

	while (!qu.empty()) {
		int size = qu.size();

		for (int i = 0; i < size; i++) {
			Node* node = qu.front();
			qu.pop();

			vector<Node*> children = node->children;
			for (int i = 0; i < children.size(); i++) {
				cout << children.at(i)->value << " ";
				qu.push(children.at(i));
			}
		}
		cout << endl;
	}
}

//int main() {
//
//	int arr[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
//
//	Node* result = buildTree(arr, 11, 3);
//
//	printTree(result);
//
//	cout << getHeight(result);
//
//	return 0;
//}