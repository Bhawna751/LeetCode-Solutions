class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];
        int cnt=0;
        for(int i=0;i<n-1;i++){
            long long left = prefix[i];
            long long right = prefix[n-1] - prefix[i];
            if(left >= right) cnt++;
        }
        return cnt;
    }
};