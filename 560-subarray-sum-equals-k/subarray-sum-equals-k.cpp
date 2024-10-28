class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mpp;
        mpp[0] = 1;
        int sum=0, cnt=0;
        for(int it:nums){
            sum += it;
            int remove = sum-k;
            cnt += mpp[remove];
            mpp[sum]++;
        }
        return cnt;

    }
};