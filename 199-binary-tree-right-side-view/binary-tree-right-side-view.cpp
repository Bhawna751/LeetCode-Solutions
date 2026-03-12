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
    vector<vector<int>> solve(TreeNode *root){
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            for(int i=0;i<n;i++){
                TreeNode *cur = q.front();
                lvl.push_back(cur->val);
                q.pop();
                if(cur->left!=nullptr)q.push(cur->left);
                if(cur->right!=nullptr)q.push(cur->right);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
     vector<int> ans;
     vector<vector<int>> lvlorder = solve(root);
     for(auto it:lvlorder){
        ans.push_back(it.back());
     }   
     return ans;
    }
};