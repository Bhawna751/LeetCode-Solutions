class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string>st;
        for(auto it:words) st.emplace(it);
        vector<string>ans;
        for(auto it:words){
            for(int j=0;j<it.length();j++){
                string temp;
                for(int k=j;k<it.length();k++){
                    temp += it[k];
                    if(temp != it && st.find(temp)!=st.end()){
                        if(find(ans.begin(),ans.end(),temp) == ans.end()) ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};