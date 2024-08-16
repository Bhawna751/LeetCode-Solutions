class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        if(n==0)return 0;
        int mini = arrays[0][0], maxi = arrays[0].back();
        int dist = 0;
        for(int i=1;i<n;i++){
            int curMin = arrays[i][0];
            int curMax = arrays[i].back();
            dist = max(dist, abs(curMax - mini));
            dist = max(dist, abs(curMin - maxi));
            mini = min(mini,curMin);
            maxi = max(maxi,curMax);
        }
        return dist;
    }
};