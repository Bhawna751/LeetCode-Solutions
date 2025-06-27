class Solution {
    bool checkK(string& s, string ans, int k) {
        int j = 0, m = ans.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ans[j])
                j++;
            if (j == m) {
                --k;
                if (k == 0)
                    return true;
                j = 0;
            }
        }
        return k <= 0;
    }
    string dfs(string& s, string& ans, int k) {
        int val = 0;
        string r = "";
        for (char ch = 'z'; ch >= 'a'; ch--) {
            if (checkK(s, ans + ch, k)) {
                ans += ch;
                string tmp = ch + dfs(s, ans, k);
                // cout << tmp << " ";
                if (val < tmp.size()) {
                    r = tmp;
                    val = tmp.size();
                }
                ans.pop_back();
            }
        }
        return r;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        return dfs(s, ans, k);
    }
};