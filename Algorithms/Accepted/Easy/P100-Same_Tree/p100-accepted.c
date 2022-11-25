/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!p && !q)
        return true;
    else if (!p || !q)
        return false;
    if (q->val != p->val) return false;

    if (q->val == q->val){
        return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left) );
    }
    return false;

}