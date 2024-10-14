class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<int> pq;
        for(auto it:nums)pq.push(it);
        while(k--){
            int maxi = pq.top();
            ans += maxi;
            pq.pop();
            pq.push(ceil(maxi/3.0));
        }
        return ans;
    }
};