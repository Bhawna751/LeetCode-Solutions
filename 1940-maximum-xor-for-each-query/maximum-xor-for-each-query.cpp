class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxi = pow(2,maximumBit)-1;//maxi = 3
        vector<int> ans;
        for(int i=1;i<nums.size();i++){//nums ->   
            nums[i]^=nums[i-1];
        }
        while(!nums.empty()){
            int temp = nums.back();//temp = 0
            nums.pop_back();
            ans.push_back(maxi^temp);//ans -> 0 3 2 3
        }
        return ans;
    }
};