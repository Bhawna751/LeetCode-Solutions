class Solution {
public:
    bool possible(int day, vector<int> &bloomDay, int m ,int k){
        int n = bloomDay.size();
        int cnt = 0, b=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                b += cnt/k;
                cnt=0;
            }
        }
        b += cnt/k;
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long bound  = m*1ll*k*1ll;
        if(bound > n)return -1;
        int mini = 1e9, maxi = -1e9;
        for(int i=0;i<n;i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int ans=-1;
        int low = mini, high=maxi;
        while(low<=high){
            int day = (low+high)/2;
            if(possible(day, bloomDay, m, k)){
                ans = day;
                high = day-1;
            }
            else low = day+1;
        }
        return ans;
    }
};