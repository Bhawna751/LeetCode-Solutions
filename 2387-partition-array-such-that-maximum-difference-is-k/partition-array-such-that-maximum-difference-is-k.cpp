class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());//1 2 3 5 6
        int ans = 1, mini = nums[0], maxi = nums[0];//ans=1, mini=1, maxi=1
        for(int it: nums){
            mini = min(mini, it);//mini = 5
            maxi = max(maxi, it);//maxi = 6
            if(maxi - mini > k){
                ans++;//ans = 2
                mini = it;
                maxi = it;
            }
        }
        return ans;
    }
};