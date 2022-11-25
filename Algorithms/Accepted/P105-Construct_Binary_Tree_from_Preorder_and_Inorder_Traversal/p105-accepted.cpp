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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        
        TreeNode * root = new TreeNode (preorder[0]);
        int lens = preorder.size();
        
        for (int i=0; i<lens; ++i) {
            if (root->val == inorder[i]) {
                vector<int> newinl (inorder.begin(), inorder.begin() + i);
                preorder.erase(preorder.begin());
                root->left = buildTree (preorder, newinl);
                
                vector<int> newinr (inorder.begin()+i+1, inorder.end());
                root->right = buildTree (preorder, newinr);
                break;
            }
        }
        
        return root;
    }
};