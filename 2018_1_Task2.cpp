#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

struct Node {

	char value;
	Node* left;
	Node* middle;
	Node* right;


};

int findHeight(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	
	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);
	int middleHeight = findHeight(root->middle);

	if (leftHeight >= middleHeight && leftHeight >= rightHeight) {
		return leftHeight + 1;
	}
	if (middleHeight >= leftHeight && middleHeight >= rightHeight) {
		return middleHeight + 1;
	}
	return rightHeight + 1;
}

void readLast(Node* root) {

	queue<Node*> qu;
	qu.push(root);
	
	int height = findHeight(root);
	int currentLevel = 1;

	while (!qu.empty()) {
		int size = qu.size();
		for (int i = 0; i < size; i++) {
			Node* node = qu.front();
			qu.pop();
			if (currentLevel == height) {
				cout << node->value << " ";
			}
			if (node->left != nullptr) qu.push(node->left);
			if (node->right != nullptr) qu.push(node->right);
			if (node->middle != nullptr) qu.push(node->middle);
		}
		currentLevel++;
	}


}

string convertTreeToString(Node* tree) {
	string str;
	if (tree == nullptr) {
		return "* ";
	}
	str += "( ";
	str.push_back(tree->value);
	str += " ";
	return str + convertTreeToString(tree->left) + convertTreeToString(tree->middle) + convertTreeToString(tree->right) + " )";
}

void serialize(Node* tree, char* filePath) {
	ofstream myfile;
	myfile.open(filePath);
	myfile << convertTreeToString(tree);
	myfile.close();
}


//int main() {
//
//	Node* n1 = new Node{ 'c', nullptr, nullptr, nullptr };
//	Node* n2 = new Node{ 'a', nullptr, nullptr, nullptr };
//	Node* n3 = new Node{ 't', nullptr, nullptr, nullptr };
//	Node* n4 = new Node{ 'p', nullptr, nullptr, nullptr };
//	Node* n5 = new Node{ 'q', nullptr, nullptr, nullptr };
//	Node* n6 = new Node{ 'r', n1, n2, nullptr };
//	Node* n7 = new Node{ 's', nullptr, nullptr, n3 };
//	Node* n8 = new Node{ 'x', n4, n5, n6 };
//	Node* n9 = new Node{ 'y', nullptr, nullptr, n7 };
//	Node* n10 = new Node{ 'b', n8, n9, nullptr };
//
//	readLast(n10);
//
//	cout << endl;
//	
//	serialize(n10, "serializedTree.txt");
//	return 0;
//}