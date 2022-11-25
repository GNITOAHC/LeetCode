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
    ListNode* mergeTwo(ListNode* a, ListNode* b){
        ListNode * cur;
        ListNode * r;
        if (a->val < b->val){
            cur = a;
            a = a->next;
        }
        else {
            cur = b;
            b = b->next;
        }
        r = cur;
        while (a && b){
            if (a->val <= b->val){
                cur->next = a;
                a = a->next;
                cur = cur->next;
            }
            else {
                cur->next = b;
                b = b->next;
                cur = cur->next;
            }
        }
        
        if (a)
            cur->next = a;
        else if (b)
            cur->next = b;
        
        return r;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        int nonNULL = 0;
        while (lists[nonNULL] == NULL){
            ++nonNULL;
            if (nonNULL >= lists.size())
                return NULL;
        }
        
        if (nonNULL == lists.size())
            return lists[nonNULL];
        
        for (int i=nonNULL+1; i<lists.size(); ++i){
            if (lists[i] == NULL)
                continue;
            lists[nonNULL] = mergeTwo(lists[nonNULL], lists[i]);
        }
        
        return lists[nonNULL];
    }
};