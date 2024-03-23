class Solution {
public:
    int image(long long n,int length){
        long long ans=0;
        if(length%2==1){
            n = n/10;
        }
        while(n>0){
            ans = ans * 10 + n % 10;
            n = n/10;
        }
        return ans;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        long long first = pow(10,(intLength+1)/2 -1);
        long long last = pow(10,(intLength+1)/2);
        long long pal = pow(10,intLength/2);
        for(int it:queries){
            if(first+it > last){
                ans.push_back(-1);
            }
            else{
                long long i = (first + it -1) * pal;
                long long j = image(first + it -1,intLength);
                ans.push_back(i+j);
            }
        }
        return ans;
    }
};