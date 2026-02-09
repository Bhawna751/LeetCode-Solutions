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
    void inorder(TreeNode* root, vector<int>&in){
        if(!root)return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode *balanced(vector<int>&in, int root, int last){
        if(root>last)return nullptr;
        int mid = (root+last)/2;
        TreeNode *l= balanced(in , root, mid-1);
        TreeNode *r = balanced(in, mid+1, last);
        return new TreeNode(in[mid], l,r);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return balanced(in,0,in.size()-1);
    }
};