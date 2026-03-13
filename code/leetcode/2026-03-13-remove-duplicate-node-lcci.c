/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeDuplicateNodes(struct ListNode* head) {
	if (!head || !head->next) return head;

	struct ListNode *p = head;
	bool track[20001] = {0};
	track[p->val] = 1;

	while(p->next) {
		if (track[p->next->val] == 1){
			p->next = p->next->next;
		}
		else{ 
			track[p->next->val] = 1;
			p = p->next;
		}

	}

	return head;
}