class Solution {
public:
    bool checkStrings(string s1, string s2) {

        long mul1 = 1;
        long mul2 = 1;
        const int MOD = INT_MAX;

        for(int i = 1 ; i < s1.size(); i+=2){
            mul1 = (mul1 * s1[i]) % MOD;
            mul2 = (mul2 * s2[i]) % MOD;
        }

        if(mul1 != mul2) return false;

        mul1 = 1;
        mul2 = 1;

        for(int i = 0 ; i < s1.size(); i+=2){
            mul1 = (mul1 * s1[i]) % MOD;
            mul2 = (mul2 * s2[i]) % MOD;
        }

        if(mul1 != mul2) return false;

        return true;
        return 420==69;
    }
};