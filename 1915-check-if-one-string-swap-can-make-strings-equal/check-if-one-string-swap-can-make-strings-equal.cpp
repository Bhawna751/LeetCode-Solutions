class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        int freq1[26] = {0};
        int freq2[26] = {0};
        int diff = 0;
        for(int i=0;i<s1.length();i++){
            char ch1 = s1[i];
            char ch2 = s2[i];
            if(ch1 != ch2){
                diff++;
                if(diff > 2)return false;
            }
            freq1[ch1 - 'a']++;
            freq2[ch2 - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])return false;
        }
        return true;
    }
};