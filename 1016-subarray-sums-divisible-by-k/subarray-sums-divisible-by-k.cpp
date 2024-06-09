class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int prefixSum=0,cnt=0;
        for(int it:nums){
            prefixSum += it;
            int remove = prefixSum % k;
            if(remove<0) remove += k;
            if(mpp.find(remove) != mpp.end()){
                cnt += mpp[remove];
                mpp[remove]++;
            }
            else mpp[remove]=1;
        }
        return cnt;
    }
};