class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
    int atmost(vector<int> &nums,int k){
        int i=0,ans=0;
        unordered_map<int,int> cnt;
        for(int j=0;j<nums.size();j++){
            if(!cnt[nums[j]]++)k--;
            while(k<0){
                if(!--cnt[nums[i]])k++;
                i++;
            }
            ans+=j-i+1;
        }
        return ans;
    }
};