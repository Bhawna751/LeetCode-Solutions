class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mpp;
        unordered_set<int> st;
        vector<int> ans;
        for(auto &query:queries){
            int ball = query[0];
            int color = query[1];
            if(mpp.count(ball)){
                int old = mpp[ball];
                if(old!=color){
                    mpp[ball]=color;
                    if(st.count(old) && 
                        std::find_if(mpp.begin(),mpp.end(),[old](const std::pair<int,int> &p){
                            return p.second==old;
                        }) == mpp.end()){
                        st.erase(old);
                    }
                    st.insert(color);
                }
            }
            else{
                mpp[ball]=color;
                st.insert(color);
            }
            ans.push_back(st.size());
        }
        return ans;
    }
};