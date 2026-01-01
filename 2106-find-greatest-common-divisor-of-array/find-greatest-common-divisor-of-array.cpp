class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int n1= nums[0];
        int n2 = nums[n-1];
        int ans=1;
        for(int i=1;i<=min(n1,n2);i++){
            if(n1 % i == 0 && n2 % i == 0){
                ans = max(ans,i);
            }
        }
        return ans;
    }
};