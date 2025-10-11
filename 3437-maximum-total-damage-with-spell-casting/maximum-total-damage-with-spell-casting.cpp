class Solution {
public:
    long long solve(vector<long long>&dp, map<int,int>&freq, vector<int>&unique, int ind){
        if(ind==unique.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long notpick = solve(dp,freq,unique,ind+1);
        long long pick = 0;
        int next = ind+1;
        while(next < unique.size() && unique[next]-unique[ind] <= 2) next++;
        pick = (long long)freq[unique[ind]] * unique[ind] + solve(dp,freq,unique,next);
        return dp[ind] = max(pick,notpick);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>freq;
        vector<int>unique;
        for(auto it:power){
            freq[it]++;
        }
        for(auto it: freq){
            unique.push_back(it.first);
        }
        vector<long long> dp(freq.size(),-1);
        return solve(dp, freq,unique,0);
    }
};