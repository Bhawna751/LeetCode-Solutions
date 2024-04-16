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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            i++;
            if(depth==i)break;
            int n=q.size();
            for(int j=0;j<n;j++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        int n=q.size();
        for(int k=0;k<n;k++){
            TreeNode* temp = q.front();q.pop();
            TreeNode* l = temp->left, *r=temp->right;
            temp->left = new TreeNode(val);
            temp->left->left=l;
            temp->right = new TreeNode(val);
            temp->right->right=r;
        }
        return root;
    }
};