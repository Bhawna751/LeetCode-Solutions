class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long patch =0 ;
        int cnt=0,ind=0;
        while(patch<n){
            if(ind<nums.size() && patch+1 >= nums[ind]){
                patch += nums[ind];
                ind++;
            }
            else{
                patch += (patch+1);
                cnt++;
            }

        }
        return cnt;
    }
};