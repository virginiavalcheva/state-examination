#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
	if (first == nullptr) return second;
	if (second == nullptr)  return first;
	ListNode* sorted;

	if (first->val <= second->val) {
		sorted = first;
		first = first->next;
	}
	else {
		sorted = second;
		second = second->next;
	}

	ListNode* prev = sorted;
	while (first && second) {
		int firstVal = first->val;
		int secondVal = second->val;
		if (firstVal <= secondVal) {
			prev->next = first;
			first = first->next;
		}
		else {
			prev->next = second;
			second = second->next;
		}
		prev = prev->next;
	}
	if (first) {
		prev->next = first;
	}
	if (second) {
		prev->next = second;
	}

	return sorted;
}

//int main() {
//	ListNode* first = new ListNode(1);
//	first->next = new ListNode(2);
//	first->next->next = new ListNode(4);
//	ListNode* second = new ListNode(1);
//	second->next = new ListNode(3);
//	second->next->next = new ListNode(4);
//	ListNode* merged = mergeTwoLists(first, second);
//	while (merged) {
//		cout << merged->val;
//		merged = merged->next;
//	}
//
//	return 0;
//}