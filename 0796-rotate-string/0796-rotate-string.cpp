class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())return false;
        int n=s.length();
        int i=0;
        while(i<n){
            if(s==goal)return true;
            char ch = s[0];
            for(int j=0;j<n-1;j++) s[j] = s[j+1];// s - bcdea
            s[n-1] = ch;
            i++;
        }
        return false;
    }
};