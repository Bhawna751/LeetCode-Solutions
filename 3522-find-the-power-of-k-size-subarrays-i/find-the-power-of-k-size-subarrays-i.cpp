class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        for(int i=0;i<=n-k;i++){
            bool valid = true;
            for(int j=i;j<i+k-1;j++){
                if(nums[j+1]!=nums[j] + 1){
                    valid = false;
                    break;
                }
            }
            if(valid) ans[i] = nums[i+k-1];
            else ans[i]=-1;
        }
        return ans;
    }
};