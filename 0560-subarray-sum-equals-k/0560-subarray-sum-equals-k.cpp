class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        int presum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            int remove = presum-k;
            cnt += m[remove];
            m[presum] += 1;
        }
        return cnt;
    }
};