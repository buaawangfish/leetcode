#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	ListNode* front_pt = node->next;
	ListNode* back_pt = node;
	
};