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
    void traversal(TreeNode * child, TreeNode *parent, unordered_map<TreeNode*, vector<TreeNode*>> & graph,
        unordered_set<TreeNode*> &leaf){
        if(!child) return;
        if(!child->left && !child->right) leaf.insert(child);
        if(parent){
            graph[parent].push_back(child);
            graph[child].push_back(parent);
        }
        traversal(child->left, child, graph, leaf);
        traversal(child->right, child, graph, leaf);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaf;
        traversal(root, nullptr, graph, leaf);
        int ans = 0;
        for(auto it: leaf){
            queue<TreeNode*> bfs;
            unordered_set<TreeNode*> vis;
            bfs.push(it);
            vis.insert(it);
            for(int i =0 ;i<= distance;i++){
                int size = bfs.size();
                for(int j=0;j<size;j++){
                    TreeNode* cur = bfs.front();
                    bfs.pop();
                    if(leaf.count(cur) && cur!=it) ans++;
                    if(graph.count(cur)){
                        for(auto a: graph[cur]){
                            if(!vis.count(a)){
                                bfs.push(a);
                                vis.insert(a);
                            }
                        }
                    }
                }
            }
        }
        return ans/2;
    }
};