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
    TreeNode* solve(string &traversal, int &i, int d){
        if(i>=traversal.size()) return nullptr;
        int cnt = 0;
        while(i + cnt < traversal.size() && traversal[i+cnt] == '-'){
            cnt++;
        }
        if(d!=cnt) return nullptr;
        i += cnt;
        int val=0;
        while(i < traversal.size() && isdigit(traversal[i])){
            val = val * 10 + (traversal[i]-'0');
            i++;
        }
        TreeNode *node = new TreeNode(val);
        node->left = solve(traversal,i,d+1);
        node->right = solve(traversal,i,d+1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return solve(traversal,i,0);
    }
};