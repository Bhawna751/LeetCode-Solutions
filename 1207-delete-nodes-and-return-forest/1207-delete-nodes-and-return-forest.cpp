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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                if(st.find(cur->left->val) != st.end()){
                    cur->left = nullptr;
                }
            }
            if(cur->right){
                q.push(cur->right);
                if(st.find(cur->right->val) != st.end()){
                    cur->right = nullptr;
                }
            }
            if(st.find(cur->val) != st.end()){
                if(cur->left) ans.push_back(cur->left);
                if(cur->right) ans.push_back(cur->right);
            }
        }
        if(st.find(root->val) == st.end()) ans.push_back(root);
        return ans;
    }
};