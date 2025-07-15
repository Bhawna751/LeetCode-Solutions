class Solution {
public:
    long long calTotalH(int hr, vector<int>piles){
        long long totalH=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalH += ceil((double)piles[i]/(double)hr);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =piles.size();
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            maxi = max(maxi, piles[i]);
        }
        int low=1, high=maxi;
        while(low<=high){
            int mid= (low+high)/2;
            int totalH = calTotalH(mid,piles);
            if(totalH <= h) high = mid-1;
            else low=mid+1;
        }
        return low;
    }
};