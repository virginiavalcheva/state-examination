#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
	char a;
	int b;
	vector<Node> children;
public:
	int sum() {
		return b;
	}
	char val() {
		return a;
	}
	vector<Node> getChildren() const {
		return children;
	}
	void addChild(Node child) {
		children.push_back(child);
	}
	Node(char a, int b, vector<Node> children) {
		this->a = a;
		this->b = b;
		this->children = children;
	}
};

int findBranch(vector<pair<string, long long>> branches, Node tree, long long sum, string word) {
	vector<Node> children = tree.getChildren();
	for (Node child : children) {
		long long newSum = sum + child.sum();
		string newWord = word + child.val();
		pair<string, long long> p(newWord, newSum);
		branches.push_back(p);
		findBranch(branches, child, newSum, newWord);
	}
	return sum;
}

int sumVal(Node v1, Node v2) {
	vector<pair<string, long long>> branchesU;
	vector<pair<string, long long>> branchesV;
	findBranch(branchesU, v1, 0, "");
	findBranch(branchesV, v2, 0, "");
	int sum = 0;
	for (int i = 0; i < branchesU.size(); i++) {
		for (int j = 0; j < branchesV.size(); j++) {
			if (branchesU[i].first.compare(branchesV[j].first) == 0) {
				sum += (branchesU[i].second + branchesV[j].second);
			}
		}
	}
	return sum;
}

//
//int main() {
//
//	return 0;
//}