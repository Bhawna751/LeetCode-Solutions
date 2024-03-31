class Solution {
public:
    bool isPalindrome(string s){
        int left=0,right=s.length()-1;
        while(left<right){
            if(s[left]!=s[right])return false;
            left++;right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)return s;
        int maxlen=1,first=0,last=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            for(int j=0;j<i;j++){
                if(s[j]==s[i] && (i-j<=2||dp[j+1][i-1])){
                    dp[j][i]=true;
                    if(i-j+1>maxlen){
                        maxlen=i-j+1;
                        first=j;last=i;
                    }
                }
            }
        }
        return s.substr(first,last-first+1);
    }
};