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
#define pb push_back
#define p push
#define db(x) cout << "DEBUG " << x << endl;
class Solution {
private:
    vector<vector<int>> list;
    
    vector<vector<int>> bfs (TreeNode * root) {
        list[0].pb(root->val);
        int lvl = 1, count = 0, tmp = 0;
        queue<TreeNode *> q;
        
        if (root->left) {
            q.p(root->left);
            ++count;
        }
        if (root->right) {
            q.p(root->right);
            ++count;
        }
        
        while (!q.empty()) {
            tmp = 0;
            list.pb(vector<int> ());
            for (int i=0; i<count; ++i) {
                list[lvl].pb(q.front()->val);
                if (q.front()->left) {
                    q.p(q.front()->left);
                    ++tmp;
                }
                if (q.front()->right) {
                    q.p(q.front()->right);
                    ++tmp;
                }
                q.pop();
            }
            ++lvl;
            count = tmp;
        }
        
        return list;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return list;
        list.pb(vector<int>());
        return bfs (root);
    }
};