class Solution {
public:
    int minBitFlips(int start, int goal) {
        //1010
        //0111
        //1101
        int a = (start ^ goal);
        int cnt=0;
        for(int i =0;i<32;i++){
            if(a&(1<<i))cnt++;
        }
        return cnt;
    }
};