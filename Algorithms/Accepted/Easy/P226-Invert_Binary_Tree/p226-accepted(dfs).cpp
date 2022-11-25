/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef struct TreeNode TreeNode;
class Solution {
public:
    TreeNode * dfstrans (TreeNode * root) {
        if (!root) return NULL;
        dfstrans (root->left);
        dfstrans (root->right);
        TreeNode * tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        dfstrans (root);
        return root;
    }
};