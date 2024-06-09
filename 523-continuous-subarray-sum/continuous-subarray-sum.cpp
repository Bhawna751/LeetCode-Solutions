class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {//23 2 4 6 7 k=6
        unordered_map<int,int> mpp;
        int prefixSum=0;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];// ps = 5
            prefixSum = prefixSum % k;//ps = 5
            if(prefixSum == 0 && i>=1)return true;// 
            if(mpp.find(prefixSum)!=mpp.end()){//
                if(i-mpp[prefixSum] > 1) return true;//2-0=2
            }
            else mpp[prefixSum] = i;//mpp---> _ 1 _ _ _ 0
        }
        return false;
    }
};