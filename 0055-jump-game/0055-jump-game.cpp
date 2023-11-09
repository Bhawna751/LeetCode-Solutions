class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ans[0]=true;
        for(int i=1;i<n;i++){
            for(int j = i-1;j>=0;j--){
                if(ans[j]&&j+nums[j]>=i){
                    ans[i]=true;
                    break;
                }
            }
        }
        return ans[n-1];
    }
};