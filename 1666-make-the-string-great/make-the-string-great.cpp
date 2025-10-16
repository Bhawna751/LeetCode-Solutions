class Solution {
public:
    string makeGood(string s) {
        int ind=0;
        while(ind!=s.size()){
            ind = s.size();
            for(int i=0;i+1<s.size();i++){
                if(abs(s[i]-s[i+1]) == 32) s = s.substr(0,i) + s.substr(i+2);
            }
        }
        return s;
    }
};