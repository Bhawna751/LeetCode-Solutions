class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flip=0;
        for(int i=0;i<n;i++){
            if((nums[i]==1 && flip%2!=0) || (nums[i]==0 && flip%2==0)) flip++;
        }
        return flip;
    }
};