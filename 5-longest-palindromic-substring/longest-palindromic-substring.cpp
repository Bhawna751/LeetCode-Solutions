class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), maxLen=1, start=0,end=0;
        if(n<=1) return s;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        dp[0][0] = true;
        for(int i=1;i<n;i++){
            dp[i][i]=true;
            for(int j=0;j<i;j++){
                if(s[i] == s[j] && (i-j<=2 || dp[j+1][i-1])){
                    dp[j][i]=true;
                    if(i-j+1 > maxLen){
                        maxLen = i-j+1;
                        start=j;
                        end=i;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};