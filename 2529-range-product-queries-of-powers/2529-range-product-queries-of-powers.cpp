class Solution {
public:
    static constexpr int mod = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;//1 2 4 8
        vector<int> ans;// n = 0
        int bit = 1;//bit = 16
        while(n){
            if(n%2 == 1)powers.push_back(bit);
            n =n/2;
            bit = bit*2;
        }
        for(auto it: queries){//it 0,3
            int cur=1;// cur=64
            for(int i = it[0];i <= it[1];i++){
                cur=static_cast<long long>(cur) * powers[i] % mod;
            }
            ans.push_back(cur);// ans -> 2,4,64
        }
        return ans;
    }
};