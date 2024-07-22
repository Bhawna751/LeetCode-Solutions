class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int,string> mpp;
        for(int i=0;i<n;i++){
            mpp[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end());
        vector<string>ans(n);
        for(int i = n-1;i>=0;i--){
            ans[n-i-1] = mpp[heights[i]];
        }
        return ans;
    }
};