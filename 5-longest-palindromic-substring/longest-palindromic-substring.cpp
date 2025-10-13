class Solution {
public:
    // bool helper(string s, int i, int j){
    //     int l=i, r=j-1;
    //     while(l<r){
    //         if(s[l]!=s[r])return false;
    //         l++;r--;
    //     }
    //     return true;
    // }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1)return s;
        int len=1, start=0,end=0;
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            for(int j=0;j<i;j++){
                if(s[i]==s[j] && (i-j<=2 || dp[j+1][i-1])){
                    dp[j][i]=true;
                    if(i-j+1>len){
                        len=i-j+1;
                        start=j;
                        end=i;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};