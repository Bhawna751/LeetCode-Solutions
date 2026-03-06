class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i=0;
        for(;s[i]=='0';i++);
        while(i!=n && s[i]!='0')i++;
        while(s[i]){
            if(s[i]=='1') return false;
            i++;
        }
        return true;
     }
};