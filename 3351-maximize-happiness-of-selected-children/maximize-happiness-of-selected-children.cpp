class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        int cnt=0;
        while(k--){
            ans += max(happiness[cnt]-cnt,0);
            cnt++;
        }
        return ans;
    }
};