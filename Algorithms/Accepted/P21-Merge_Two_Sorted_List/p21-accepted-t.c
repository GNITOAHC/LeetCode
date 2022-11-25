/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* ln;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ln cur1 = list1, cur2 = list2, ans = NULL, end_a = NULL;
    if (cur1->val < cur2->val){
        ans = end_a = cur1;
        cur1 = cur1->next;
    }
    else {
        ans = end_a = cur2;
        cur2 = cur2->next;
    }
    while (cur1 && cur2){
        if (cur1->val < cur2->val){
            end_a->next = cur1;
            cur1 = cur1->next;
        }
        else {
            end_a->next = cur2;
            cur2 = cur2->next;
        }
        end_a = end_a->next;
    }
    if (cur1)
        end_a->next = cur1;
    else
        end_a->next = cur2;
    return ans;
}
