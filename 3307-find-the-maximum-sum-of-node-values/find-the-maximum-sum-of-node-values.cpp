class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans =0;
        int min_add=1e9, min_sub=1e9;
        int even=1;
        for(int it: nums){
            ans+= it;
            int xorop = it ^ k;
            if(xorop>it){
                ans+= xorop - it;
                min_add = min(min_add,xorop-it);
                even = even^1;
            }
            else{
                min_sub = min(min_sub, it-xorop);
            }
        }
            if(even == 0)ans+= max(-min_add,-min_sub);
            return ans;
    }
};