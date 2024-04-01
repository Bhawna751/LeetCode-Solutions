class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(),ans=0,flag=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                ans++;
                flag=1;
            }
            else if(s[i]==' '&&flag==1)break;
        }
        return ans;
    }
};