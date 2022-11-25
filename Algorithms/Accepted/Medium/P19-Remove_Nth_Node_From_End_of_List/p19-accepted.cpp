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
typedef struct ListNode ListNode;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return nullptr;
        }
        
        ListNode * fast = head, * slow = head;
        for (int i=0; i<n; ++i)
            fast = fast->next;

        if (fast == NULL) { // the target is the first node
            return head->next;
        }
        
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode * target = slow->next;
        
        target = target->next;
        slow->next = target;

        return head;
    }
};