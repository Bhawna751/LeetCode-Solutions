class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves=0;//2
        sort(nums.begin(),nums.end());//1 2 3 2 3 7
        for(int i=1;i<nums.size();i++){//2
           if(nums[i]==nums[i-1]){//2==2
                moves++;
                nums[i]++;
           }
           if(nums[i]<nums[i-1]){
                int dif=nums[i-1]-nums[i]+1;
                moves+= dif;
                nums[i] += dif;
           }
        }
        return moves;
    }
};