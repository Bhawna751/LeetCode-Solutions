class Solution {
public:
    int bitcount(int num){
        unsigned int cnt=0;
        while(num){
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
    int minimizeXor(int num1, int num2) {
        int cnt1 = bitcount(num1);
        int cnt2 = bitcount(num2);
        while(cnt1>cnt2){
            num1 &= num1-1;
            cnt1 = cnt1-1;
        }
        while(cnt1<cnt2){
            num1 |= num1 +1;
            cnt1 +=1;
        }
        return num1;
    }
};