class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> one(n+2), zero(n+2);
        for(int i = 1; i <= n; i++){
            if((i%2 && s[i-1] == '0') || (i%2 == 0 && s[i-1] =='1')) one[i]++;
            else zero[i]++;

        }
        for(int i=1;i<n+2;i++){
            one[i] += one[i-1];
            zero[i] += zero[i-1];
        }

        if(n%2 == 0){
            return min(one[n], zero[n]);
        }

        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            ans = min({ans,one[i] + zero[n] - zero[i],zero[i] + one[n] - one[i]});
            if(ans == -1) cout<<i;

        }
        return ans;
    }
};