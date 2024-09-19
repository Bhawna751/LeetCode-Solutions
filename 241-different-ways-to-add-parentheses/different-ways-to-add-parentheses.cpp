class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<vector<vector<int>>> dp(expression.length(), vector<vector<int>>(expression.length()));
        return compute(expression, dp, 0, expression.length() - 1);
    }
private:
    vector<int> compute(string& expression,vector<vector<vector<int>>>& dp, int start,int end) {
        if (!dp[start][end].empty()) {
            return dp[start][end];
        }
        vector<int> ans;
        if (start == end) {
            ans.push_back(expression[start] - '0');
            return ans;
        }
        if (end - start == 1 && isdigit(expression[start])) {
            int tens = expression[start] - '0';
            int ones = expression[end] - '0';
            ans.push_back(10 * tens + ones);
            return ans;
        }
        for (int i = start; i <= end; i++) {
            char cur = expression[i];
            if (isdigit(cur)) {
                continue;
            }

            vector<int> left =
                compute(expression, dp, start, i - 1);
            vector<int> right =
                compute(expression, dp, i + 1, end);

            for (int lit : left) {
                for (int rit : right) {
                    switch (cur) {
                        case '+':
                            ans.push_back(lit + rit);
                            break;
                        case '-':
                            ans.push_back(lit - rit);
                            break;
                        case '*':
                            ans.push_back(lit * rit);
                            break;
                    }
                }
            }
        }
        dp[start][end] = ans;
        return ans;
    }
};