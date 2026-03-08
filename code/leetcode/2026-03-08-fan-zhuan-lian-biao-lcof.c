/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* trainningPlan(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    else {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        while (curr)
        {
            struct ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}