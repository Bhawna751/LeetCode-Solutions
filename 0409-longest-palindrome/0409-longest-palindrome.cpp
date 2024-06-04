class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        for(char ch: s){
            mpp[ch]++;
        }
        int ans=0;
        bool odd=false;
        for(auto& it: mpp){
            int freq = it.second;
            if(freq%2 == 0) ans+=freq;
            else{
                ans+= freq-1;
                odd=true;
            }
        }
        if(odd) return ans+1;
        return ans;
    }
};