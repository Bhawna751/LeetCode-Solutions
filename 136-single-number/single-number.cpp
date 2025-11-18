class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int it:nums){
            ans = ans^it;
        }
        return ans;
    }
};