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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> sum;
        while(!q.empty()){
            int lvl = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *cur  = q.front();
                q.pop();
                lvl += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            sum.push_back(lvl);
        }
        q.push(root);
        int ind = 1;
        root->val=0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *cur = q.front();
                q.pop();
                int sibling = (cur->left ? cur->left->val : 0)+ (cur->right ? cur->right->val : 0);
                if(cur->left){
                    cur->left->val = sum[ind] - sibling;
                    q.push(cur->left);
                }if(cur->right){
                    cur->right->val = sum[ind] - sibling;
                    q.push(cur->right);
                }
            }
            ind++;
        }
        return root;
    }
};