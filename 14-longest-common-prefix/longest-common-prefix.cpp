class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[strs.size()-1];
        for(int i=0;i<min(first.length(), last.length()); i++){
            if(first[i]!=last[i])break;
            ans += first[i];
        }
        return ans;
    }
};