class Solution {
public:
    string A;
    string B;
    int n;
    int m;
    int dp[1001][1001];
    int f(int i, int j){
        if(i == 0 && j == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == 0 && j > 0){
            dp[i][j] = f(i, j - 1) + (int)B[j-1];
            return dp[i][j];
        }
        if(j == 0 && i > 0){
            dp[i][j] = f(i - 1, j) + (int)A[i-1];
            return dp[i][j];
        }
        if(A[i-1] == B[j-1]){
            dp[i][j] = f(i - 1, j - 1);
            return dp[i][j];
        }
        int opt1 = f(i - 1, j) + (int)A[i-1];
        int opt2 = f(i, j - 1) + (int)B[j-1];
        dp[i][j] = min(opt1, opt2);
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        A = s1;
        B = s2;
        n = (int)A.size();
        m = (int)B.size();
        memset(dp, -1, sizeof(dp));
        return f(n, m);
    }
};