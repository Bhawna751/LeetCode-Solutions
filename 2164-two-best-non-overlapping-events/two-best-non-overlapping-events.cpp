class Solution {
public:
    int helper(int ind,int cnt, vector<vector<int>> &dp, vector<vector<int>>&events){
        if(ind >= events.size() || cnt == 2)return 0;
        if(dp[ind][cnt] == -1){
            int end = events[ind][1];
            int l = ind+1, r = events.size()-1;
            while(l<r){
                int mid = (l+r)/2;
                if(events[mid][0] > end) r=mid;
                else l=mid+1;
            }
            int pick = events[ind][2] + (l<events.size() && events[l][0] > end ? helper(l,cnt+1,dp,events) : 0);
            int notpick = helper(ind+1,cnt,dp,events);
            dp[ind][cnt] = max(pick,notpick);
        }
        return dp[ind][cnt];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        sort(events.begin(), events.end());
        return helper(0,0,dp,events);
    }
};