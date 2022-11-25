
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode * ln;
typedef struct ListNode Ln;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (!list1) return list2;
    if (!list2) return list1;
    
    ln cur1 = list1, cur2 = list2;
    ln head = malloc(sizeof(Ln));
    ln temp = head;
    
    if(cur1->val <= cur2->val){
        temp->val = cur1->val;
        temp->next = NULL;
        cur1 = cur1->next;
    } else {
        temp->val = cur2->val;
        temp->next = NULL;
        cur2 = cur2->next;
    }
    
    while (cur1 && cur2){
        if (cur1->val <= cur2->val){
            ln newNode = (ln) malloc(sizeof(Ln));
            newNode->val = cur1->val;
            newNode->next = NULL;
            
            temp->next = newNode;
            temp = temp->next;
            
            cur1 = cur1->next;
        } else {
            ln newNode = (ln) malloc (sizeof(Ln));
            newNode->val = cur2->val;
            newNode->next = NULL;
            
            temp->next = newNode;
            temp = temp->next;
            
            cur2 = cur2->next;
        }
    }
    
    if (cur1){
        while (cur1){
            ln newNode = (ln) malloc (sizeof(Ln));
            newNode->val = cur1->val;
            newNode->next = NULL;
            
            temp->next = newNode;
            temp = temp->next;
            
            cur1 = cur1->next;
        }
    } else {
        while (cur2){
            ln newNode = (ln) malloc (sizeof(Ln));
            newNode->val = cur2->val;
            newNode->next = NULL;
            
            temp->next = newNode;
            temp = temp->next;
            
            cur2 = cur2->next;
        }
    }
        
    
    
    return head;
}










