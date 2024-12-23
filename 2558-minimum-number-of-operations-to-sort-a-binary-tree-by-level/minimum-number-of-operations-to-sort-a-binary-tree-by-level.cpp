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
    int swap(vector<int> &arr){
        int swaps=0;
        vector<int> result=arr;
        sort(result.begin(), result.end());
        unordered_map<int,int> pos;
        for(int i=0;i<arr.size();i++) pos[arr[i]] = i;
        for(int i=0;i<arr.size();i++) {
            if(arr[i] != result[i]) swaps++;
            int cur= pos[result[i]];
            pos[arr[i]] = cur;
            ::swap(arr[cur], arr[i]);
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int total=0;
        while(!q.empty()){
            int lvl = q.size();
            vector<int> lvlValue(lvl);
            for(int i=0;i<lvl;i++){
                TreeNode* node = q.front();
                q.pop();
                lvlValue[i] = node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            total += swap(lvlValue);
        }
        return total;
    }
};