class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n =nums.size()/2;
        int total =accumulate(nums.begin(), nums.end(), 0);
        

        vector<vector<int>> left(n+1), right(n+1);

        for(int mask = 0;mask < (1<<n); mask++){
            int ind=0, leftSum = 0, rightSum =0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    ind++;
                    leftSum += nums[i];
                    rightSum += nums[i+n];
                }
            }
            left[ind].push_back(leftSum);
            right[ind].push_back(rightSum);
        }
        for(int i=0;i<=n;i++){
            sort(right[i].begin(), right[i].end());
        }
        int leftmax = abs(total - 2*left[n][0]);
        int rightmax = abs(total - 2*left[n][0]);
        int ans = min(leftmax, rightmax);

        for(int i=1;i<n;i++){
            for(auto &it: left[i]){
                int j = (total - 2*it)/2;
                int rightind = n-i;
                auto &k = right[rightind];
                auto iter = lower_bound(k.begin(), k.end(), j);
                if(iter != k.end()) ans = min(ans, abs(total - 2*(it+(*iter))));
            }
        }
        return ans;
    }
};