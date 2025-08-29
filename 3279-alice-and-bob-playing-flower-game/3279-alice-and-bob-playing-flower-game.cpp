class Solution {
public:
    long long flowerGame(int n, int m) {
        long long on = (n+1)/2;
        long long om = (m+1)/2;
        long long en = n/2;
        long long em = m/2;
        long long ans = on * em + om * en;
        return ans;
    }
};