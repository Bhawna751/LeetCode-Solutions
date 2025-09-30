class Solution {
public:
    string minWindow(string s, string t) {
        int len =1e9;
        int ind = -1;
        int freq[256] = {0};
        for(char c: t) freq[c]++;
        int cnt = 0, l=0, r=0;
        while(r<s.length()){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;
            while(cnt == t.length()){
                if(r-l+1 < len){
                    len = r-l+1;
                    ind= l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (ind == -1) ? "" : s.substr(ind,len);
    }
};