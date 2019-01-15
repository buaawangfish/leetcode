#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* pointA = headA;
	ListNode* pointB = headB;
	int len_diff = 0;
	while (pointA && pointB)
	{
		if (pointA == pointB)
			return pointA;
		pointA = pointA->next;
		pointB = pointB->next;		
	}
	if ((!pointA) && (!pointB))
		return nullptr;

	if (!pointA)
	{
		while (pointB)
		{
			pointB = pointB->next;
			len_diff++;
		}
	}
	else if (!pointB)
	{
		while (pointA)
		{
			pointA = pointA->next;
			len_diff--;
		}
	}

	pointA = headA;
	pointB = headB;
	if (len_diff > 0)
	{
		while (len_diff > 0)
		{
			pointB = pointB->next;
			len_diff--;
		}
		while (pointA != pointB)
		{
			pointA = pointA->next;
			pointB = pointB->next;
		}
		return pointA;
	}
	else
	{
		while (len_diff < 0)
		{
			pointB = pointB->next;
			len_diff++
		}	
		while (pointA != pointB)
		{
			pointA = pointA->next;
			pointB = pointB->next;
		}
		return pointA;
	}
}

