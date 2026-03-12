/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
	struct ListNode *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	struct ListNode *prev = NULL, *curr = slow, *next;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	while(prev&&head) {
		if (prev->val != head->val) {
			return false;
		}
		prev = prev->next;
		head = head->next;
	}
	return true;
}