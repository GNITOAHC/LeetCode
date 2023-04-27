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
    TreeNode* balanceBST(TreeNode* root) {
        return helper(root);
    }
private:
    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) return nullptr;

        root->left = helper(root->left);
        root->right = helper(root->right);

        int l = height(root->left), r = height(root->right);
        int balanceFactor = l - r;

        if (balanceFactor > 1) { // left higher
            // If left->left < left->right: LR rotate
            // leftRotate, rightRotate
            if (height(root->left->left) < height(root->left->right)) {
                root->left = leftRotate(root->left);
            }
            // Else SingleLeftRotate LL rotate
            root = rightRotate(root);
            return helper(root);
        } else if (balanceFactor < -1) { // right higher
            // If right->left > right->right: RL rotate
            // rightRotate, leftRotate
            if (height(root->right->left) > height(root->right->right)) {
                root->right = rightRotate(root->right);
            }
            // Else SingleRightRotate RR rotate
            root = leftRotate(root);
            return helper(root);
        }

        return root;
    }

    TreeNode* rightRotate(TreeNode* K2) {
        if (K2 == nullptr) return nullptr;
        TreeNode* K1 = K2->left;
        K2->left = K1->right;
        K1->right = K2;
        return K1;
    }

    TreeNode* leftRotate(TreeNode* K1) {
        if (K1 == nullptr) return nullptr;
        TreeNode* K2 = K1->right;
        K1->right = K2->left;
        K2->left = K1;
        return K2;
    }
    
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return (1 + max(height(root->left), height(root->right)));
    }
 };