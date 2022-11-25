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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp = 0;
        ListNode * head = l1;
        ListNode * l1pre = l1;
        while (l1 && l2){
            tmp += l1->val + l2->val;
            l1->val = tmp%10;
            tmp /= 10;
            l1pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == 0 && l2 == 0 && tmp != 0)
            l1pre->next = new ListNode(tmp);
        else if (l1){
            while (l1){
                tmp += l1->val;
                l1->val = tmp%10;
                tmp /= 10;
                l1pre = l1;
                l1 = l1->next;
            }
            if (tmp != 0){
                l1pre->next = new ListNode(tmp);
            }
        }
        else if (l2){
            l1 = l1pre;
            l1->next = l2;
            l1 = l1->next;
            while(l1){
                tmp += l1->val;
                l1->val = tmp%10;
                tmp /= 10;
                l1pre = l1;
                l1 = l1->next;
            }
            if (tmp != 0)
                l1pre->next = new ListNode(tmp);
        }
        
        return head;
    }
};