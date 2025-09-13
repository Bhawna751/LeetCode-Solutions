class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int c=0,v=0;
        for(char ch= 'a';ch<='z';ch++ ){
            if(ch == 'a' || ch == 'e' || ch=='i' || ch=='o' || ch=='u') v = max(v,mpp[ch]);
            else c = max(c,mpp[ch]);
        }
        return v+c;
    }
};