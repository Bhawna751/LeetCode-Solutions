class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        vector<int> num(100);
        int ans=0;
        for(auto it: dominoes){
            int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            ans += num[val];
            num[val]++;
        }
        return ans;
    }
};