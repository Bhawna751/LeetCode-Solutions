class Solution {
public:
    void subsets(int ind,string s,vector<vector<string>> &ans,vector<string>&part){
        if(ind==s.size()){
            ans.push_back(part);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                part.push_back(s.substr(ind,i+1-ind));
                subsets(i+1,s,ans,part);
                part.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int ind,int i){
        while(ind<=i){
            if(s[ind]!=s[i]){
                return false;
            }
            ind++;
            i--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        subsets(0,s,ans,part);
        return ans;
    }
};