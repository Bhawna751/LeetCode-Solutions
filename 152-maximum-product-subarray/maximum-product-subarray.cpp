class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini=1, maxi = 1, ans = -1e9;
        for(int it: nums){
            if(it < 0) swap(maxi,mini);
            mini = min(mini * it, it);
            maxi = max(maxi * it, it);
            ans = max(ans, maxi);
        }
        return ans;
    }
};