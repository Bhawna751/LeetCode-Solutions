class Solution {
public:
    void solve(string s,unordered_set<string> &wordSet,vector<string> &temp,vector<string> &ans){
        if(0==s.length()){
            string cur="";
            for(auto it:temp) cur+= it+" ";
            cur.pop_back();
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<s.length();i++){//4-->10
            if(wordSet.count(s.substr(0,i+1))){
                temp.push_back(s.substr(0,i+1));
                solve(s.substr(i+1),wordSet,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        vector<string> ans,temp;
        solve(s,wordSet,temp,ans);
        return ans;    
    }

};