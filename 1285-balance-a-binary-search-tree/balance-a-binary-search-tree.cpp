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
    void inorder(TreeNode* root, vector<int> &in){
        if(!root) return ;
        inorder(root->left,in);
        in.push_back(root->val);//1 2 3 4
        inorder(root->right,in);

    }
    TreeNode* balance(vector<int>&in, int root, int last){
        if(root>last)return nullptr;//root=0 last=0
        int mid= root + (last-root)/2;//1
        TreeNode* left= balance(in,root,mid-1);//(0,0) 
        TreeNode* right= balance(in,mid+1,last);//(1,0)
        return new TreeNode(in[mid],left,right);//(2,)
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return balance(in,0,in.size()-1);
    }
};