class Solution {
public:
    long long totalHours(vector<int> &piles, int rate){
        int n  = piles.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans += ceil((double)piles[i] / (double)rate);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid = (low+high)/2;
            long long hours = totalHours(piles,mid);
            if(hours <= h)high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};