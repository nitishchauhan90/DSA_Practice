/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

public:
    void solve(TreeNode* root, int& k, int& result) {
        if (root == nullptr) {
            return;
        }
        solve(root->left, k, result);
        if (k == 1) {
            k--;
            result = root->val;

            return;

        }
        else {
            k--;
        }
        solve(root->right, k, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }
        int result;
        solve(root, k, result);
        return result;
    }
};