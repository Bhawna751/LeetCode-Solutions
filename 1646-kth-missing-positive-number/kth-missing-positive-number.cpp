class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n =arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int mno=arr[mid]-(mid+1);
            if(mno<k) low  = mid+1;
            else high = mid-1;
        }
        return k + high + 1;
    }
};