#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* middleNode(ListNode* head) {
	ListNode* fast_pt = head;
	ListNode* slow_pt = head;
	while (fast_pt)
	{
		fast_pt = fast_pt->next;
		if (!fast_pt)
			return slow_pt;
		fast_pt = fast_pt->next;
		slow_pt = slow_pt->next;
	}
	return slow_pt;
}