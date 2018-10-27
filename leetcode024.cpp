#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	if (head->next == NULL) return head;
	if (head == NULL) return head;
	ListNode* new_head = new ListNode(0);
	new_head->next = head;
	ListNode* ptr = new_head;
	ListNode* temp = ptr->next->next;
	while (temp != NULL)
	{
		ptr->next->next = temp->next;
		temp->next = ptr->next;
		ptr->next = temp;
		if (temp->next->next == NULL) break;
		else
		{
			ptr = ptr->next->next;
			temp = ptr->next->next;
		}
	}
	return new_head->next;
}

int main(){

	getchar();
	return 0;
}
