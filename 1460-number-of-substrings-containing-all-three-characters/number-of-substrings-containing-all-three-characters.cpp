class Solution {
public:
    bool required(vector<int> &freq){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0, r =0;
        vector<int> freq(3,0);
        int ans=0;
        while(r<n){
            char cur = s[r];
            freq[cur-'a']++;
            while(required(freq)){
                ans += n - r;
                char lch  = s[l];
                freq[lch - 'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};