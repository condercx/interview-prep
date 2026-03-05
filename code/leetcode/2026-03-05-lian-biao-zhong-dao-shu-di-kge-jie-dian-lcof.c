/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* trainingPlan(struct ListNode* head, int cnt) {
	if (head == NULL) return NULL;

	int i = 0;
	struct ListNode *fast = head;

	while(fast) {
		if(i < cnt) {
			++i;
		} else {
			head = head->next;
		}
		fast = fast->next;
	}

	return head;
}