class Solution {
public:
    void generate(int n, string cur, vector<string>&ans){
        if(cur.size() == n){
            ans.push_back(cur);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(cur.size()>0 && cur.back()==ch) continue;
            generate(n,cur+ch, ans);
        }
    }
    string getHappyString(int n, int k) {
        string cur="";
        vector<string> ans;
        generate(n, cur,ans);
        if(ans.size()<k)return "";
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};