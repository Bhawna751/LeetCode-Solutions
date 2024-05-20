class Solution {
public:
    int sum(vector<int>& nums,int ind,int cur){
        if(ind==nums.size()) return cur;
        int withele = sum (nums,ind+1,cur^nums[ind]);
        int without = sum(nums,ind+1,cur);
        return withele + without;
    }
    int subsetXORSum(vector<int>& nums) {
        return sum(nums,0,0);
    }
};