class Solution {
public:
    long long minimumSteps(string s) {
        long long total = 0, black = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0') total += (long long) black;
            else black++;
        }
        return total;
    }
};