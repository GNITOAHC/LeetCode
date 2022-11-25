/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    ListNode * prune(ListNode *pruneHead, const int pruneCount) {
        int num = pruneCount;
        for (int i=0; i<num; ++i) {
            pruneHead = pruneHead->next;
        }
        return pruneHead;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        // count lens
        ListNode *count = headA;
        int lensA = 1, lensB = 1;
        while (count->next != nullptr) {
            count = count->next;
            ++lensA;
        }
        count = headB;
        while (count->next != nullptr) {
            count = count->next;
            ++lensB;
        }
        
        // prune the head of the longest listnode
        if (lensA > lensB)
            headA = prune(headA, lensA - lensB);
        else if (lensA < lensB)
            headB = prune(headB, lensB-lensA);
        
        // Traverse and compare
        while (headA) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
    }
};