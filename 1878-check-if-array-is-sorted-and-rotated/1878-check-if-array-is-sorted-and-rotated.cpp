class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(cnt>1) return false;
            else if(nums[i] > nums[i+1]) cnt++;
        }
        if(nums[nums.size()-1] > nums[0])cnt++;
        if(cnt>1) return false;
        else return true;
    }
};