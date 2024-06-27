class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
         unordered_map<int, int> degree;

        for (vector<int> edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (auto& nodes : degree){
            if (nodes.second == edges.size()) {
                return nodes.first;
            }
        }

        return -1;
    }
};