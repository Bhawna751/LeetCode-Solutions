class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> left(n);
        int ans=0;
        left[0] = values[0];
        for(int i=1;i<n;i++){
            int curright=values[i]-i;
            ans=max(ans, curright + left[i-1]);
            int curleft = values[i]+i;
            left[i] = max(left[i-1], curleft);
        }
        return ans;
    }
};