class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        if(s.length()  == k) return true;
        vector<int> freq(26);
        int cnt=0;
        for(auto it:s) freq[it-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i] % 2 == 1)cnt++;
        }
        return cnt<=k;
    }
};