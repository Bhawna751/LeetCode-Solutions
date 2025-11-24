class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        vector<int>ans;
        vector<vector<int>> ind;
        for(int i=0;i<n;i++) ind.push_back({nums[i],i});
        sort(ind.begin(), ind.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0]<b[0];
        });
        while(l<r){
            int sum = ind[l][0] + ind[r][0];
            if(sum==target){
                ans.push_back(ind[l][1]);
                ans.push_back(ind[r][1]);
                return ans;
            }
            else if(sum<target)l++;
            else r--;
        }
        return {-1,-1};
    }
};