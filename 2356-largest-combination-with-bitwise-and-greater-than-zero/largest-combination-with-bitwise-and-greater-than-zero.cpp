class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt = 0;//10000,10001,1000111,111110,1100,11000,1110
        for(int i=0;i<32;i++){//i=4
            int cur = 0;
            for(int it:candidates){
                if( (it & (1 << i)) != 0)cur++;//cur = 2 (16,17,62,24)
            }
            cnt = max(cnt,cur);//cnt = 4
        }
        return cnt;
    }
};