class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,i=0,cnt=0,n=nums.size();
        for(int j=0;j<n;j++){
            if(nums[j] & 1)
                --k,cnt=0;
            while(k==0){
                k+=nums[i++]&1,cnt++;
            }
            ans+=cnt;
        }
        return ans;
    }
};