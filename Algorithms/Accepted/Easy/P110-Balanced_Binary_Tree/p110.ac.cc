/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool travel(struct TreeNode * root, int * height){
    if (!root){
        * height = 0;
        return true;
    }
    int hl, hr;
    bool b = (travel(root->left, &hl) && travel(root->right, &hr));
    * height = hl > hr ? hl+1 : hr+1;
    if ((hl - hr) > 1 || (hl - hr) < -1){
        return false;
    }
    return b;
}

bool isBalanced(struct TreeNode* root){
    int h;
    return travel(root, &h);
}