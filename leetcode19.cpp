#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* new_head = new ListNode(0);
	new_head->next = head;

	ListNode* first_ptr = new_head;
	ListNode* second_ptr = new_head;
	for (int i = 0; i <= n; i++)
	{
		second_ptr = second_ptr->next;
	}
	while (second_ptr != NULL)
	{
		first_ptr = first_ptr->next;
		second_ptr = second_ptr->next;
	}
	ListNode* temp = first_ptr->next;
	first_ptr->next = temp->next;
	delete temp;
	return new_head->next;
}

int main()
{

	getchar();
	return 0;
}