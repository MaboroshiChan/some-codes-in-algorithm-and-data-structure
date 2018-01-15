#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode()
	{
		this->next = NULL;
	}
	ListNode(int x) :val(x) { this->next = NULL; }
};


void LoopReverseLinkedlist(ListNode* &head)
{
	if (head == NULL) { return; }
	ListNode* ptr = head;
	ListNode* middle = head;
	ListNode* behind = head;
	ptr = ptr->next;
	middle->next = NULL;
	middle = ptr;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		middle->next = behind;
		behind= middle;
		middle = ptr;
	}
	ptr->next = behind;
}

void RecursionReversed(ListNode* &head)
{
	if (head == NULL||head->next==NULL) { return; }// return到前一段的递归;
	RecursionReversed(head->next);
	head->next->next = head;
	head->next = NULL;
}
void deletenode(ListNode* node)
{
	if (node = NULL) { return; }
	if (node->next = NULL){
		delete node;
	}
	ListNode* ptr;
	node->val = node->next->val;
	ptr = node->next->next;
	node->next->next = NULL;
	node->next = ptr;
}
void insert(ListNode* &head, int val)
{
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		head->next = new ListNode(val);
	}
	else {
		insert(head->next, val);
	}
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL || l2 == NULL) {
		return NULL;
	}
	ListNode* ptr1 = l1;
	ListNode* ptr2 = l2;
	int excess = 0;
	int sum;
	while (ptr1->next != NULL && ptr2->next != NULL) {
		sum = ptr1->val + ptr2->val + excess;
		if (sum >= 10) {
			ptr2->val = sum - 10;
			excess = 1;
		}
		else {
			ptr2->val = sum;
			excess = 0;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if (ptr1->next != NULL || ptr2->next != NULL) {   //
		sum = ptr1->val + ptr2->val + excess;
		if (sum >= 10) {
			ptr2->val = sum - 10;
			excess = 1;
		}
		else {
			ptr2->val = sum;
			excess = 0;
		}
		if (ptr1->next == NULL) {
			while (ptr2 != NULL) {
				ptr2 = ptr2->next;
				if (excess == 1 && ptr2->next == NULL&&ptr2->val == 9) {
					ptr2->val = 0;
					ptr2->next = new ListNode(1);
					break;
				}
				if (ptr2->val + excess >= 10) {
					ptr2->val += excess - 10;
					excess == 1;
				}
				else {
					ptr2->val += excess;
					excess = 0;
					break;
				}
			}
		}
		else {   //ptr2->next == NULL
			ptr2->next = ptr1->next;
			while (ptr2 != NULL) {
				ptr2 = ptr2->next;
				if (excess == 1 && ptr2->next == NULL&&ptr2->val == 9) {
					ptr2->val = 0;
					ptr2->next = new ListNode(1);
					break;
				}
				if (ptr2->val + excess >= 10)
				{
					ptr2->val += excess - 10;
					excess == 1;
				}
				else {
					ptr2->val += excess;
					excess = 0;
					break;
				}
			}
		}
		return l2;
	}  //
	else {
		sum = ptr1->val + ptr2->val + excess;
		if (sum >= 10) {
			ptr2->val = sum - 10;
			excess = 1;
		}
		else {
			ptr2->val = sum;
			excess = 0;
		}
		if (excess == 1) {
			ptr2->next = new ListNode(1);
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return l2;
}
int main()
{
	ListNode* A = new ListNode(1);
	ListNode* B = new ListNode(9);
	insert(B, 9);

	ListNode* ptr = addTwoNumbers(A,B);
	while (ptr != NULL) {
		cout << ptr -> val << " " ;
		ptr = ptr->next;
	}
	return 0;
}
