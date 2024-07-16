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
    TreeNode* LCA(TreeNode *root, int p,int q){
        if(root == nullptr) return nullptr;
        if(root->val == p || root->val == q) return root;
        TreeNode *left = LCA(root->left,p,q);
        TreeNode *right = LCA(root->right,p,q);
        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        else return root;
    }

    bool findPath(TreeNode *root, string &path, int val){
        if(root == nullptr)return false;
        if(root->val == val) return true;
        path.push_back('L');
        if(findPath(root->left,path,val)) return true;
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right, path,val)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = LCA(root,startValue,destValue);
        string startPath, destPath;
        findPath(lca,startPath,startValue);
        findPath(lca,destPath,destValue);
        string dir;
        dir.append(startPath.length(),'U');
        dir.append(destPath);
        return dir;
    }
};