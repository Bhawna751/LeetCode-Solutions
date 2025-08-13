class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;//  [3,4,7,-2,2,1,4,2] and k=7
        mpp[0]=1;
        int presum = 0, cnt=0;
        for(int i=0;i<nums.size();i++){
            presum+= nums[i];
            int remainder = presum-k;
            cnt+= mpp[remainder];
            mpp[presum]++;
        }
        return cnt;
    }
};