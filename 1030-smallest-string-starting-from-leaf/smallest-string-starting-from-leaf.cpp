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
private:
    string smallest = "~";
    void solve(TreeNode *root,string path){
        if(!root)return;
        path = (char)('a'+root->val) + path;
        if(!root->left && !root->right){
            smallest = min(smallest,path);
        }
        solve(root->left,path);
        solve(root->right,path);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return  smallest;
    }
};