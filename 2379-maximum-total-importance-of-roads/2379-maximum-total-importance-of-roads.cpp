class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n,0);

        for (vector<int> edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        sort (degree.begin(),degree.end());
        long long ans = 0;
        for(long long i=0;i<n;i++){
            ans += ((i+1)*degree[i]);
            
        }
        return ans;
    }
};