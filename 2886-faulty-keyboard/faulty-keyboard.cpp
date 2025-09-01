class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(char c:s){
            if(c!='i')ans.push_back(c);
            else {
                int l=0,r=ans.size()-1;
                while(l<=r){
                    swap(ans[l],ans[r]);
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};