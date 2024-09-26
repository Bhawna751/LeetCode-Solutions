class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = n+m, sum =0;
        for(int i=0;i<m;i++){
            sum += rolls[i];
        }
        int rem = mean * total - sum;
        int x = rem / n;
        vector<int> ans(n,x);
        if(rem > 6*n || rem<n) return {};
        int mod = rem % n;
        for(int i =0;i<mod;i++) ans[i]++;
        return ans;
    }
};