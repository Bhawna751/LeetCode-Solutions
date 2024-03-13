class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path;
        subset(0,s,ans,path);
        return ans;
    }
    void subset(int ind,string s,vector<vector<string>> &ans,vector<string> &path){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                subset(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int ind, int i){
        while(ind<=i){
            if(s[ind++]!=s[i--])return false;
        }
        return true;
    }
};