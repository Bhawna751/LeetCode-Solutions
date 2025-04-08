class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt =0;
        int temp;
        while(true){
            unordered_map<int,int>mpp;
            temp=0;
            for(int it:nums){
                if(++mpp[it]==2)temp++;
            }
            if(temp==0)break;
            nums.erase(nums.begin(), nums.begin() + min(3,(int)nums.size()));
            cnt++;
        }
        return cnt;
    }
};