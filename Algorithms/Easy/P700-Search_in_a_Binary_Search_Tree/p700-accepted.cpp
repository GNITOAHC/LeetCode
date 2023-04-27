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
#define dbl cout << "debug left" << endl;
#define dbr cout << "debug right" << endl;
#define r cout << "root->val = " << root->val << endl;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // r;
        if (val == root->val)
            return root;
        if (val > root->val){
            // dbr;
            if (root->right == NULL)
                return NULL;
            return searchBST(root->right, val);
        }
        if (val < root->val){
            // dbl;
            if (root->left == NULL)
                return NULL;
            return searchBST(root->left, val);
        }
        
        return NULL;
    }
};