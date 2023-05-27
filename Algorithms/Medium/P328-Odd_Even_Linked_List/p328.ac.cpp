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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // If no node or one node

        // First node is consider odd
        ListNode *odd_head = head, *even_head = head->next;
        ListNode *odd_cur = odd_head, *even_cur = even_head;

        ListNode* cur = even_head->next; // Start from the third one
        
        int idx = 3;
        while (cur != nullptr) {
            if (idx % 2 == 0) {
                // even
                even_cur->next = cur;
                even_cur = even_cur->next;
            } else {
                // odd
                odd_cur->next = cur;
                odd_cur = odd_cur->next;
            }
            cur = cur->next;
            ++idx;
        }

        even_cur->next = nullptr; // Make sure lastNode->next point ot nullptr
        odd_cur->next = even_head; // Concatenate oddLast with evenFirst

        return head;
    }
};