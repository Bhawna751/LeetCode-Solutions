class Solution {
public:
    void solve(string &s,unordered_set<string> &wordSet,string &cur,vector<string> &ans,int ind){
        if(ind==s.length()){
            ans.push_back(cur);
            return;
        }
        for(int i=ind+1;i<=s.length();i++){//4-->10
            string word = s.substr(ind,i-ind);//word = s
            if(wordSet.find(word) != wordSet.end()){
                string org = cur;//org = "cat"
                if(!cur.empty()) cur += " ";
                cur+= word;//cur = "cats"
                solve(s,wordSet,cur,ans,i);
                cur=org;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        vector<string> ans;
        string cur;
        solve(s,wordSet,cur,ans,0);
        return ans;    
    }

};