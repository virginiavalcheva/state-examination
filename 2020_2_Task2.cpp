#include <iostream>
#include <queue>

using namespace std;

struct Node { 
	char text;
	Node *left, *right; 
};

int height(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
}

void printLevel(Node* node, int level, int height) {
	if (node == nullptr) {
		cout << "X";
	}
	if (level == 1) {
		cout << node->text;
	}
	if (level > 1) {
		printLevel(node->left, level - 1, height);
		printLevel(node->right, level - 1, height);
	}
}

void printText(Node* root) {
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printLevel(root, i, h);
		cout << endl;
	}
}


Node* createNode(char ch) {
	Node* node = new Node;
	node->text = ch;
	node->left = node->right = nullptr;
	return node;
}

int countNodes(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}

void printTextWithQueue(Node* root) {
	if (root == nullptr) {
		return;
	}
	queue<Node*> queue;
	queue.push(root);

	int count = countNodes(root);

	while (!queue.empty()) {

		int size = queue.size();
		while (size) {
			Node* n = queue.front();
			queue.pop();
			size--;

			if (n) {
				cout << n->text;
				count--;

				queue.push(n->left);
				queue.push(n->right);
				if (count == 0) {
					return;
				}
			}
			else {
				cout << "X";
			}
		}
		cout << endl;
	}
}



//int main() {
//	
//	Node* root = createNode('I');
//	
//	root->left = createNode('a');
//	root->right = createNode('m');
//	root->left->left = createNode('V');
//	//root->left->right = createNode('e');
//	root->right->left = createNode('r');
//	root->left->left->left = createNode('k');
//	
//	//printText(root);
//	printTextWithQueue(root);
//	return 0;
//}
