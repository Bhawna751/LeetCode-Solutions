class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";//he
        int n = s.size();
        int spacecnt=0;
        int i=0;
        while(i<n && spacecnt < k){
            if(s[i]!=' '){
                ans +=s[i];
                i++;
            }
            else if(s[i]==' '){
                spacecnt++;
                if(spacecnt==k)break;
                else{
                 ans +=s[i];
                 i++;  
                }
            }

        }
        return ans;
    }
};