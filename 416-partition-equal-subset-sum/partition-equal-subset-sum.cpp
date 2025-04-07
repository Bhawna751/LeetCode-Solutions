class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        else{
            int k = sum/2;
            vector<bool>prev(k+1,false);
            prev[0]=true;
            if(nums[0]<=k)prev[nums[0]]=true;
            for(int i=1;i<n;i++){
                vector<bool>cur(k+1, false);
                for(int j=1;j<=k;j++){
                    bool notpick = prev[j];
                    bool pick = false;
                    if(nums[i] <= j) pick = prev[j-nums[i]];
                    cur[j] = notpick || pick;
                }
                prev = cur;
            }
            return prev[k];
        }
    }
};