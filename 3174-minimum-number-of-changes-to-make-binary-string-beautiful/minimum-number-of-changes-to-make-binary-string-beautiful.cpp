class Solution {
public:
    int minChanges(string s) {
        char c = s[0];//c = 0
        int cnt=0, ans =0;
        for(int i=0;i<s.length();i++){
            if(s[i] == c){
                cnt++;//cnt=1
                continue;
            }
            if(cnt %2==0) cnt=1;
            else{
                cnt=0;
                ans++;//ans = 1
            }
            c=s[i];
        }   
        return ans;
    }
};