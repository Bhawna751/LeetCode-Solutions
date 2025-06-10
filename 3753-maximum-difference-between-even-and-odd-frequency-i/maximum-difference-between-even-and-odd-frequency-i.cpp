class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        int a2 = 0,a1=s.length();
        for(int i=0;i<freq.size();i++){
            if(freq[i] % 2 == 1) a2 = max(a2,freq[i]);
            if(freq[i] % 2 == 0 && freq[i] > 0)a1 = min(a1,freq[i]);
        }
        return a2-a1;
    }
};