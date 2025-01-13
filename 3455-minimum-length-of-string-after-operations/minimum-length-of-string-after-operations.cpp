class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int deleteop=0;
        unordered_map<char,int> freqMpp;
        for(char ch:s){
            freqMpp[ch]++;
        }
        for(auto it:freqMpp){
            int freq = it.second;
            if(freq%2 != 0)deleteop += freq-1;
            else deleteop += freq-2;
        }
        return n-deleteop;
    }
};