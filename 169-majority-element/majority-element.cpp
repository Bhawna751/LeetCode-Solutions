class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ans = nums[i];
            }else if(nums[i]==ans){
                cnt++;
            }
            else cnt--;
        }
        cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==ans)cnt++;
        }
        if(cnt > n/2)return ans;
        
        return ans;
    }
};