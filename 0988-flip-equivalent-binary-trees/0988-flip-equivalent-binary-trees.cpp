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
    void solve(TreeNode * root){
        if(root==nullptr) return ;
        solve(root->left);
        solve(root->right);
        if(!root->right)return;
        if(!root->left){
            root->left = root->right;
            root->right = nullptr;
            return;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(left->val > right->val){
            root->left = right;
            root->right = left;
        }
    }
    bool equivalent(TreeNode* root1, TreeNode*root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;
        return equivalent(root1->left, root2->left) && equivalent(root1->right, root2->right);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solve(root2);
        return equivalent(root1, root2);
    }
};