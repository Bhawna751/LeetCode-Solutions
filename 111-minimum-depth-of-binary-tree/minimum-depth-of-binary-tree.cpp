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
    int f(TreeNode *root){
        if(root == nullptr)return 1e9;
        if(root->left == nullptr && root->right==nullptr)return 1;
        return 1+min(f(root->left), f(root->right));
    }
    int minDepth(TreeNode* root) {
        int ans=f(root);
        return ans == 1e9?0:ans;
    }
};