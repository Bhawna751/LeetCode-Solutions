class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n =s.length();        
        int ans=0;
        int l =0;
        for(int i=0;i<s.length();i++){
            if(st.find(s[i])!=st.end()) {
                while(l<i && st.find(s[i]) != st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[i]);
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};