class Solution {
public:
    /*int f(int ind,int prevind,vector<int>& nums,int n,vector<vector<int>> &dp){
        if(ind==n)return 0;
        if(dp[ind][prevind+1]!=-1)return dp[ind][prevind+1];
        int len = 0+f(ind+1,prevind,nums,n,dp);//nottake
        if(prevind==-1||nums[ind]>nums[prevind]){
            len = max(len,1+f(ind+1,ind,nums,n,dp));//take
        }
        return dp[ind][prevind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0);
        vector<int>cur(n+1,0);
        for(int ind = n-1;ind>=0;ind--){
            for(int prevind=ind-1;prevind>=-1;prevind--){
                int len = 0+next[prevind+1];
                if(prevind==-1||nums[ind]>nums[prevind]){
                    len = max(len,1+next[ind+1]);
                } 
                cur[prevind+1]=len;
            }
            next=cur;
        }
        return next[-1+1];
    }*/
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind =abs( lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin());
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};