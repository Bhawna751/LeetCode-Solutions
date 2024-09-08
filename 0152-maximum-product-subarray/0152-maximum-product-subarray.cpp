class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];//ans = 0
        for(int i=0;i<n;i++){
            int prod = nums[i];// prod = 2
            for(int j = i+1;j<n;j++){
                ans = max(ans,prod);//ans = 0
                prod *= nums[j];// prod = 0
            }
            ans = max(ans,prod);// 0 
        } 
        return ans;
    }
};