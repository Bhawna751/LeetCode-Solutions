class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(), strs.end());
        string start = strs[0], end = strs[strs.size()-1];
        for(int i=0;i< min(start.length(),end.length()) ; i++){
            if(start[i] != end[i])break;
            ans += start[i];
        }
        return ans;
    }
};