class Solution {
public:
    bool checkRecord(string s) {
        
        int absent=0,nlate=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'A') absent++;
            if(s[i]=='L') nlate++;
            else nlate=0;
            if(absent>=2 || nlate>2) return false; 
        }
        return true;
    }
};