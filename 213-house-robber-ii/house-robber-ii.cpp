class Solution {
public:
    int solve( vector<int> &arr){
        int ind = arr.size();
        int prev2= 0, prev = arr[0];

        if(ind ==0)return arr[ind];
        if(ind<0)return 0;
        
        for(int i=1;i<ind;i++){
            int pick = arr[i];
            if(i>1)pick += prev2;
            int notpick = prev;
            int cur = max(pick ,notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1, arr2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=n-1)arr1.push_back(nums[i]);
            if(i!=0) arr2.push_back(nums[i]);

        }
        
        int ans1 = solve(arr1);
        int ans2  = solve(arr2);
        return max(ans1, ans2);
    }
};