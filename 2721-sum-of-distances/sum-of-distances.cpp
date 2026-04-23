class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);
        for(auto &it : mpp) {
            vector<int> &ind = it.second;
            int k = ind.size();
            vector<long long> prefix(k + 1, 0);
            for(int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + ind[i];
            }
            for(int i = 0; i < k; i++) {
                long long left = (long long)i * ind[i] - prefix[i];
                long long right = (prefix[k] - prefix[i]) - (long long)(k - i) * ind[i];
                ans[ind[i]] = left + right;
            }
        }
        return ans;
    }
};