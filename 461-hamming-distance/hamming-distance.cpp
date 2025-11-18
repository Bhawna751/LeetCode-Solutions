class Solution {
public:
    int hammingDistance(int x, int y) {//x=001 y=100
        int xorr = x^y;//101
        int cnt=0;
        for(int i=0;i<32;i++){
            cnt +=(xorr&1);//cnt=1
            xorr = xorr >> 1;//xorr = 010
        }
        return cnt;
    }
};