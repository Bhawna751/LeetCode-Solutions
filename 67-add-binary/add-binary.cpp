class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int n=a.length()-1,m =b.length()-1,carry=0;
        while(n>=0 ||m>=0 || carry==1){
            int total = carry;
            if(n>=0)total += a[n--]-'0';
            if(m>=0)total += b[m--]-'0';
            ans += (total%2)+'0';
            carry=total/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};