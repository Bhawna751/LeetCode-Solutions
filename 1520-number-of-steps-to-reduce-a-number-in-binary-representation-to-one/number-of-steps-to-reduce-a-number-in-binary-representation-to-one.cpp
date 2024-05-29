class Solution {
public:
    int numSteps(string s) {//1101
        int n=s.size();//4
        int op=0;
        int carry=0;
        for(int i=n-1;i>0;i--){//3
            if((s[i] + carry) % 2){//
                op += 2;
                carry = 1;
            }
            else op++;
        }
        return op + carry;
    }
};