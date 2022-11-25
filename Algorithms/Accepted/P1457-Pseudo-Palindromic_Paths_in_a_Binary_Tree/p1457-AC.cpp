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
    Solution () { 
        for (int i=0; i<10; ++i) {
            set[i] = 0;
        }
        ans = 0; 
    }
    void check_palindrome () {
        // for (int i=0; i<s.size(); ++i) printf("%d ", s[i]);
        // cout << endl;
        int count = 0;
        for (int i=0; i<10; ++i) {
            if (set[i] % 2 == 1) ++count;
        }
        if (count <= 1) ++ans;
        return;
    };
    
    void traversal (TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            ++set[ root->val ];
            check_palindrome();
            --set[ root->val ];
            return;
        }
        
        ++set[ root->val ];
        traversal(root->left);
        traversal(root->right);
        --set[ root->val ];
        return;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        traversal(root);
        return ans;
    }
private:
    vector<int> s;
    int set[10];
    int ans;
};