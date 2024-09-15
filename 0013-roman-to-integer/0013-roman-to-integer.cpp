class Solution {
public:
    int romanToInt(string s) {
        int n=s.size(),ans=0;//MCMXCIV
        unordered_map<char,int>mpp;
        mpp['I']= 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        for(int i=0;i<n;i++){
            if(mpp[s[i]]<mpp[s[i+1]]) ans = ans-mpp[s[i]];
            else ans=ans+mpp[s[i]];// ans  = 1000 - 100 + 1000 - 10 + 100 -1 + 5 = 1994
        }
        return ans;
    }
};