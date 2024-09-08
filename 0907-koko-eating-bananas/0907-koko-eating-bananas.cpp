class Solution {
public:
    int findMax(vector<int> &piles){
        int n = piles.size();
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long calculateTotalHourly(vector<int> &piles, int hourly){
        int n=piles.size();
        long long total = 0;
        for(int i = 0 ; i<n;i++){
            total += ceil( (double)(piles[i]) / (double)(hourly) );
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high){
            int mid=(low+high)/2;
            long long total = calculateTotalHourly(piles,mid);
            if(total <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};