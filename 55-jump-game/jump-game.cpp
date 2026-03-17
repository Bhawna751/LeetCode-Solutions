class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0]=true;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(prefix[j] && j + nums[j] >= i){
                    prefix[i]=true;
                    break;
                }
            }
        }
        return prefix[n-1];
    }
};