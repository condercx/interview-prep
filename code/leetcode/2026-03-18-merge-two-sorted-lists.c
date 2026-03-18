/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL) return list2;
	if (list2 == NULL) return list1;

	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode *pre = head;

	while (list1 && list2) {
		if (list1->val <= list2->val) {
			pre->next = list1;
			list1 = list1->next;
		} else {
			pre->next = list2;
			list2 = list2->next;
		}

		pre = pre->next;
	}

	pre->next = (list1 == NULL ? list2 : list1);

	return head->next;
}