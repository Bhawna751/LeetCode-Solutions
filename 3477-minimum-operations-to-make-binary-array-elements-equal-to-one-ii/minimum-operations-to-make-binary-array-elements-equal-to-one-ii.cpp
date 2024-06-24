class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();//0 1 1 0 1
        int flip=0;//flip = 4
        for(int i=0;i<n;i++){
            if((flip + nums[i])%2 == 0 ) flip++;
        }
        return flip;
    }
};