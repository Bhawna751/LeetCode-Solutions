class Solution {
public:
    int solve(int height, vector<pair<int,int>>&st){
        int l =0, r=st.size()-1;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(st[mid].first > height){
                ans = max(ans,mid);
                l = mid+1;
            }else r = mid-1;
        }
        return ans;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = heights.size();
        vector<int> ans(n,-1);
        vector<pair<int,int>> st;
        vector<vector<pair<int,int>>> q(m);
        for(int i=0;i<n;i++){
            int alice = queries[i][0];
            int bob = queries[i][1];
            if(alice > bob) swap(alice,bob);
            if(heights[alice] < heights[bob] || alice == bob) ans[i] = bob;
            else q[bob].push_back({heights[alice],i});
        }
        for(int i=m-1;i>=0;i--){
            int size = st.size();
            for(auto& it: q[i]){
                int pos = solve(it.first,st);
                if(pos<st.size() && pos>=0) ans[it.second] = st[pos].second;
            }
            while(!st.empty() && st.back().first <= heights[i]) st.pop_back();
            st.push_back({heights[i], i});
        }
        return ans;
    }
};