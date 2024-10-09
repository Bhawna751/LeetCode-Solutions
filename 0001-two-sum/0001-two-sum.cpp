class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        vector<vector<int>> ind;
        for(int i=0;i<n;i++){
            ind.push_back({nums[i],i});
        }
        sort(ind.begin(), ind.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        int left= 0, right = n-1;
        while(left<right){
            int sum = ind[left][0] + ind[right][0];
            if(sum == target){
                ans.push_back(ind[left][1]);
                ans.push_back(ind[right][1]);
                return ans;
            }
            else if(sum<target) left++;
            else right--;
        }
        return {-1,-1};
    }
};