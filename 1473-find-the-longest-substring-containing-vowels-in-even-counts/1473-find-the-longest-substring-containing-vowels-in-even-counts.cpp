class Solution {
public:
    int findTheLongestSubstring(string s) {//eleetminicoworoep
        int prefixXor=0;
        int charMap[26] = {0};
        charMap['a' - 'a'] = 1;
        charMap['e' - 'a'] = 2;
        charMap['i' - 'a'] = 4;
        charMap['o' - 'a'] = 8;
        charMap['u' - 'a'] = 16;
        vector<int> mpp(32,-1);
        /*
            -1 -1 0 -1 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1  
            longest = 3
        */
        int longest=0;
        for(int i=0;i<s.length();i++){
            prefixXor ^= charMap[s[i] - 'a'];
            if(mpp[prefixXor] == -1 && prefixXor != 0) mpp[prefixXor] = i;
            longest = max(longest,i-mpp[prefixXor]);
        }
        return longest;
    }
};