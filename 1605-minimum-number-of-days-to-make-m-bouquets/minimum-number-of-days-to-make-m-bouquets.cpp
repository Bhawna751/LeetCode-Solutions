class Solution {
public:
    bool possible(vector<int>& bloomDay,int d, int m,int k){
        int cnt =0, bouq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<= d) cnt++;
            else{
                bouq += cnt/k;
                cnt=0;
            }
        }
        bouq += cnt/k;
        return bouq >= m;
    }
    int minDays(vector<int>& bloomDay, int mc, int kc) {
        long long m = mc, k = kc;
        int n = bloomDay.size();
        if(m*k > n)return -1;
        int mini=1e9,maxi=-1e9;
        for(int i=0;i<n;i++){
            mini  = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};