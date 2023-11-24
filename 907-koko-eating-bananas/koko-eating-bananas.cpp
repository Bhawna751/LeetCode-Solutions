class Solution {
public:
    int findMax(vector<int>&v){
        int maxi=INT_MIN,n=v.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }
    long long totalH(vector<int>&v,int hourly){
        long long totalH=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            totalH += ceil((double)(v[i])/(double)(hourly));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long H=totalH(piles,mid);
            if(H<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};