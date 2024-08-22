class Solution {
public:
    int decimalToBinary(string s){
        int ans=0, n=s.length(),j=0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1') ans+= pow(2,j);
            j++;
        }
        return ans;
    }
    int findComplement(int num) {
        string s;
        while(num > 0){
            if(num & 1) s.push_back('0');
            else s.push_back('1');
            num = num >> 1;
        }   
        reverse(s.begin(), s.end());
        int ans = decimalToBinary(s);
        return ans;
    }
};