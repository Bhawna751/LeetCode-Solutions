class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i=0;
        int j=i+2;
        while(j<4){
            if(s2[i]==s1[i]){
                i++;
                j++;
                continue;
            }
            if(s2[j]==s1[i]){
                swap(s2[j],s2[i]);
            }
            i++;
            j++;
        }

        return s1==s2;
    }
};