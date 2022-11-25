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
private:
    vector<TreeNode*> helper (const int start, const int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int cur_root=start; cur_root<=end; ++cur_root) {
            vector<TreeNode*> left = helper(start, cur_root-1);
            vector<TreeNode*> right = helper(cur_root+1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode * root = new TreeNode(cur_root);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};