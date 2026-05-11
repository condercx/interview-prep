#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *fast = dummyHead;
		ListNode *slow = dummyHead;

		while(n > 0) {
		fast = fast->next;
		n--;
		}

		while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
		}

		ListNode *tmp = slow->next;
		slow->next = slow->next->next;
		delete tmp;

		return dummyHead->next;
	}
};
