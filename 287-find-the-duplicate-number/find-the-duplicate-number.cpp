class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans;
        vector<int>freq(n+1,0);
        for(int it:nums){
            freq[it]++;
        }
        for(int i=0;i<=n;i++){
            if(freq[i]>1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};