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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*>qt;
        qt.push(root);
        while(!qt.empty()){
            int qtsize = qt.size();
            vector<int>ans;
            for(int i=0;i<qtsize;i++){
                TreeNode* topi= qt.front();
                qt.pop();
                ans.push_back(topi->val);
                if(topi->left){
                    qt.push(topi->left);
                }
                if(topi->right){
                    qt.push(topi->right);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};