/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL) return false;
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while(fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}

	return false;
}


bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}
	
	struct ListNode *slow = head;
	struct ListNode *fast = head->next;  // fast 领先一步
	
	while (slow != fast) {
		// 如果 fast 到达末尾，说明无环
		if (fast == NULL || fast->next == NULL) {
			return false;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return true;  // slow == fast，有环
}