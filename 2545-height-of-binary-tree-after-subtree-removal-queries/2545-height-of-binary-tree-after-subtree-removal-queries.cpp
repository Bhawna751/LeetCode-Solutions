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
    unordered_map<int, int> firstMaxInLevel, secondMaxInLevel;
    unordered_map<int, int> nodeLevel; // node-> its level
    unordered_map<int, int> map; // node -> max level of that subtree
    unordered_map<int, int> ansMap;

public:
    int dfsSize(TreeNode* node, int lvl) {
        if (node == nullptr) return 0;
        int curr = lvl;
        curr = max(curr, dfsSize(node->left, lvl + 1));
        curr = max(curr, dfsSize(node->right, lvl + 1));

        if (!firstMaxInLevel.count(lvl)) {
            firstMaxInLevel[lvl] = curr;
        } else if (!secondMaxInLevel.count(lvl)) {
            if (firstMaxInLevel[lvl] > curr) secondMaxInLevel[lvl] = curr;
            else {
                secondMaxInLevel[lvl] = firstMaxInLevel[lvl];
                firstMaxInLevel[lvl] = curr;
            }
        } else {
            int first = firstMaxInLevel[lvl], second = secondMaxInLevel[lvl];
            if (curr >= first) {
                secondMaxInLevel[lvl] = first;
                firstMaxInLevel[lvl] = curr;
            } else if (curr > second) {
                secondMaxInLevel[lvl] = curr;
            }
        }

        map[node->val] = curr;
        nodeLevel[node->val] = lvl;
        return curr;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map.clear();
        nodeLevel.clear();
        ansMap.clear();
        dfsSize(root, 0);

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int qry = queries[i], lvl = nodeLevel[qry], maxDepth = 0;
            if (ansMap.count(qry)) {
                ans[i] = ansMap[qry];
                continue;
            }
            if (!secondMaxInLevel.count(lvl)) {
                ans[i] = nodeLevel[qry] - 1;
            } else {
                int first = firstMaxInLevel[lvl], second = secondMaxInLevel[lvl];
                int currMaxDepth = map[qry];
                if (first > currMaxDepth || second == currMaxDepth) ans[i] = first;
                else ans[i] = second;
            }
            ansMap[qry] = ans[i];
        }
        return ans;
    }
};