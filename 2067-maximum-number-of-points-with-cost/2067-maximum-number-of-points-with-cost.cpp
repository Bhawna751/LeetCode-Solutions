class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int c = points[0].size();
        vector<long long> prev(c),cur(c);
        for(auto it: points){
            long long maxi=0;
            for(int j =0;j<c;j++){
                maxi = max(maxi-1,prev[j]);
                cur[j] = maxi;
            }
            maxi =0;
            for(int j = c-1;j>=0;j--){
                maxi = max(maxi-1,prev[j]);
                cur[j] = max(cur[j], maxi) + it[j];
            }
            prev = cur;
        }
        long long ans = 0;
        for(int j = 0;j<c;j++){
            ans = max(ans,prev[j]);
        }
        return ans;
    }
};