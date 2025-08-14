class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();// [1,2,3,4]
        vector<int> ans(n);
        ans[0]=1;// ans-> 1, 1, 2, 6
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1;i>=0;i--){// ans-> 24, 12, 8,6
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }
        return ans;
    }
};