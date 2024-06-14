class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves=0;
        sort(nums.begin(),nums.end());//1 2 3 4 3 7
        for(int i=0;i<nums.size()-1;i++){//2
            while(nums[i]>=nums[i+1]){
                nums[i+1]++;
                moves++; // moves=4
            }
        }
        return moves;
    }
};