/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        
        if (root == p || root == q)
            return root;
        
        TreeNode * left, * right;
        
        left = lowestCommonAncestor (root->left, p, q);
        right = lowestCommonAncestor (root->right, p, q);
        
        if (!left && !right)
            return nullptr;
        else if (!left)
            return right;
        else if (!right)
            return left;
        return root;
    }
};