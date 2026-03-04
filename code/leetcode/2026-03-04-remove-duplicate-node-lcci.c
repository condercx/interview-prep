/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeDuplicateNodes(struct ListNode* head) {
	if (head == NULL) return NULL;
	struct ListNode *current = head;

	while (current) {
		struct ListNode *p = current;
		while (p->next) {
			if (p->next->val == current->val) {
				p->next = p->next->next;
			} else {
				p = p->next;
			}
		}
		current = current->next;
	}

	return head;
}

struct ListNode* removeDuplicateNodes(struct ListNode* head) {
	if (head == NULL) return NULL;
	bool track[20001] = {0};
	struct ListNode *p = head;
	track[head->val] = 1;

	while(p->next != NULL) {
		if (track[p->next->val] == 0) {
			track[p->next->val] = 1;
			p = p->next;
		} else {
			p->next = p->next->next;
		}
	}

	return head;
}
