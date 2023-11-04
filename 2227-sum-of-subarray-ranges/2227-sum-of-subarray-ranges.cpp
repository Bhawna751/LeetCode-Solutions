class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long ans =0, n =nums.size(),j,k;
        stack<int> s;
        for(int i =0;i<=n;i++){
            while(!s.empty()&&nums[s.top()]>(i==n? -2e9 : nums[i])){
                j=s.top(),s.pop();
                k=s.empty()?-1:s.top();
                ans -= (long)nums[j] * (i-j) * (j-k);
            }
            s.push(i);
        }
        s = stack<int>();
        for(int i=0;i<=n;i++){
            while(!s.empty() && nums[s.top()]<(i==n ? 2e9 : nums[i])){
                j=s.top(),s.pop();
                k=s.empty()?-1:s.top();
                ans += (long)nums[j] * (i-j) * (j-k);
            }
            s.push(i);
        }
        return ans;
    }
};