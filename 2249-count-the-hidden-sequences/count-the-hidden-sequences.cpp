class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long sum = 0, mn = 0, mx = 0;
        for (int n : differences) {
            sum += n;
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        return max(0L, mn - mx + upper - lower + 1);
    }
};