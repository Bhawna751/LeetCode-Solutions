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
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, bool> mpp;
        while(!st.empty()){
            TreeNode* top = st.top();
            if(!top->left && !top->right){
                st.pop();
                mpp[top] = top->val;
                continue;
            }
            if(mpp.find(top->left) != mpp.end() && mpp.find(top->right) != mpp.end()){
                st.pop();
                if(top->val == 2){
                    mpp[top] = mpp[top->left] || mpp[top->right];
                }
                else{
                    mpp[top] = mpp[top->left] && mpp[top->right];
                }
            }
            else{
                st.push(top->right);
                st.push(top->left);
            }
        }
        return mpp[root] ==1;
    }
};