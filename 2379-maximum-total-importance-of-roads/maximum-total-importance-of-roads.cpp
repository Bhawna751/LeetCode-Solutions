class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n,0);

        for (vector<int> edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort (degree.begin(),degree.end());
        long long cur=1, sum = 0;
        for(long long it : degree){
            sum += (cur*it);
            cur++;
        }
        return sum;
    }
};