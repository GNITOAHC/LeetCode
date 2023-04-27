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
    int ansMax;
public:
    Solution(): ansMax(INT32_MIN){}
    int dfs(TreeNode * n){
        int left = (n->left != NULL) ? dfs(n->left) : 0;
        int right = (n->right != NULL) ? dfs(n->right) : 0;
        int middle = n->val;
        int tmpMax = max(middle, max(left+middle, right+middle));
        ansMax = max(ansMax, max(tmpMax, middle+left+right));
        return tmpMax;
    }
    int maxPathSum(TreeNode* root) {
        // if (!root)
        //     return 0;
        dfs(root);
        return ansMax;
    }
};