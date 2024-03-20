class Solution {
public:
    int minimumLength(string s) {
        int low =0,high = s.size() - 1;
        while (low < high && s[low] == s[high]) {
            char ch = s[low];
            while (low <= high && s[low] == ch) {
                low++;
            }
            while (high >= low && s[high] == ch) {
                high--;
            }
        }

        return high - low + 1;
    }
};