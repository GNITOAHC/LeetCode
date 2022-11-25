/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fastptr = head, * slowptr = head;
        if (head == nullptr || head->next == nullptr)
            return NULL;
        do {
            if (fastptr->next == nullptr || fastptr->next->next == nullptr)
                return NULL;
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        } while (fastptr != slowptr);
        
        fastptr = head;
        while (fastptr != slowptr) {
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        
        return fastptr;
    }
};