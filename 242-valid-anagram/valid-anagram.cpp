class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mpp;
        for(char ch:s)mpp[ch]++;
        for(char ch:t)mpp[ch]--;
        for(auto it:mpp)if(it.second!=0)return false;
        return true;
    }
};