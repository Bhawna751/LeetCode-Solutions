class Solution {
public:
    long long palindrome(int j,int intLength,int exponent){
        long long j1 = pow(10,exponent);
        long long j2 = j1 + (j-1);
        string s1 = to_string(j2);
        string s2 = "";
        for(int i=1;i<=(intLength/2);i++){
            s2 += s1[i-1];
        }
        reverse(s2.begin(),s2.end());
        s1 = s1+s2;
        long long ans = stoll(s1);
        return ans;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n = queries.size();
        vector<long long> palindromes(n,0);
        int exponent;
        if(intLength%2 == 0) exponent = intLength/2 - 1;
        else exponent = intLength/2;
        int limit = 9 * pow(10,exponent);
        for(int i=0;i<n;i++){
            int j = queries[i];
            if(j>limit) palindromes[i]=-1;
            else palindromes[i] = palindrome(j,intLength,exponent);
        }
        return palindromes;
    }
};