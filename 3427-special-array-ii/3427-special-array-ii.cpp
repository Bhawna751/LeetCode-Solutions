class Solution {
public:
    bool bs(int p, int q, vector<int>&invalid){
        int left = 0, right = invalid.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            int ind = invalid[mid];
            if(ind < p)left = mid+1;
            else if(ind>q) right = mid-1;
            else return true;
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size());
        int n=nums.size();
        vector<int> invalid;
        for(int i=1;i<n;i++){
            if(nums[i] % 2 == nums[i-1] % 2)invalid.push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            vector<int> q = queries[i];
            int l = q[0];
            int r = q[1];
            bool flag = bs(l+1,r,invalid);
            if(flag)ans[i]=false;
            else ans[i]=true;
        }
        return ans;
    }
};