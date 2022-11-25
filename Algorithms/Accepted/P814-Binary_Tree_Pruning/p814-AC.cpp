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
class Solution {
public:
    bool canPrune (TreeNode * root) {
        if (root == nullptr) return true;
        if (canPrune(root->left)) {
            root->left = nullptr;
        }
        if (canPrune(root->right)) {
            root->right = nullptr;
        }
        if (root->left == nullptr && root->right == nullptr && root->val == 0) 
            return true;
        else return false;
    };
    
    TreeNode* pruneTree(TreeNode* root) {
        canPrune(root);
        if ((root->left == nullptr && root->right == nullptr && root->val == 0)) return nullptr;
        return root;
    }
};