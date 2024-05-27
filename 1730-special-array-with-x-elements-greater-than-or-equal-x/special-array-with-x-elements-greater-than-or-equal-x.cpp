class Solution {
public:
    bool check(int num, vector<int> &nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=num) return (nums.size()-i) == num;
        }
        return false;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<=n;i++){
            if(check(i,nums)) return i;
        }
        return -1;
    }
};