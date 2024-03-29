class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*std::max_element(nums.begin(),nums.end());
        int n=nums.size(),cnt=0,i=0;
        long long ans=0;
        for(int j=0;j<n;j++){
            if(nums[j]==maxi)cnt++;
            if(cnt>=k){
                for(;cnt>=k;i++){
                    ans+= n-j;
                    if(nums[i]==maxi)cnt--;
                }
            }
        }
        return ans;
    }
};