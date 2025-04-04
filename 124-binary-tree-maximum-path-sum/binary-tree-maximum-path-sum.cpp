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
    int maxi = -1e9;
    int solve(TreeNode *root, int &maxi){
        if(root==nullptr)return 0;
        int left = max(0, solve(root->left,maxi));
        int right = max(0,solve(root->right, maxi));
        maxi = max(maxi,left+right+root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root,maxi);
        return maxi;
    }
};