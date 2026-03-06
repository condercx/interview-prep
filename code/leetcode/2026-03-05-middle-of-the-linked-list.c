/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode *fast = head;

	if(fast == NULL) return NULL;
	while(fast->next != NULL) {
		fast = fast->next->next;
		head = head->next;
	}

	return head;
}