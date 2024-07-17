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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_set<int> parents;
        unordered_set<int> children;
        unordered_map<int, vector<pair<int,int>>> mpp;
        for(auto it: descriptions){
            int parent = it[0];
            int child = it[1];
            int dir = it[2];
            parents.insert(parent);
            parents.insert(child);
            children.insert(child);
            mpp[parent].emplace_back(child,dir);
        }
        for(auto it= parents.begin();it!=parents.end();){
            if(children.find(*it) != children.end()){
                it = parents.erase(it);
            }else it++;
        }
        TreeNode *root = new TreeNode(*parents.begin());
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            for(auto& it: mpp[p->val]){
                int val = it.first, left = it.second;
                TreeNode *c = new TreeNode(val);
                q.push(c);
                if(left){
                    p->left = c;
                }else{
                    p->right = c;
                }
            }
        }
        return root;
    }
};