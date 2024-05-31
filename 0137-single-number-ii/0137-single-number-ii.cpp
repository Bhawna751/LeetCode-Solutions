class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask =1,ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int i:nums){
                if(i & mask) cnt += 1;
            }
            if((cnt%3) != 0) ans += mask;
            mask = mask << 1;
        }
        return ans;
    }
};