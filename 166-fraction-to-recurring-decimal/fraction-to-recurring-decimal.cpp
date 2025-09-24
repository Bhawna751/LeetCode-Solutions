class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        if(!numerator)return "0";
        if(numerator >0 ^ denominator>0) ans += '-';
        long n = labs(numerator), d = labs(denominator);        
        long intPart = n/d;
        long rem = n%d;
        ans += to_string(intPart);
        if(rem == 0) return ans;
        ans += '.';
        unordered_map<long,int>mpp;
        while(rem!=0){
            if(mpp.find(rem) != mpp.end()){
                int pos = mpp[rem];
                ans.insert(pos,"(");
                ans += ')';
                break;
            }
            else{
                mpp[rem] = ans.length();
                rem *= 10;
                intPart = rem/d;
                rem = rem%d;
                ans += to_string(intPart);
            }
        }
        return ans;
    }
};