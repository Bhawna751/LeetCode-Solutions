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
    int diameter= 0;
    int calHeight(TreeNode *root, int &diameter){
        if(root == nullptr) return 0;
        int left = calHeight(root->left,diameter);
        int right = calHeight(root->right,diameter);
        diameter = max(diameter, left + right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calHeight(root, diameter);
        return diameter;
    }
};