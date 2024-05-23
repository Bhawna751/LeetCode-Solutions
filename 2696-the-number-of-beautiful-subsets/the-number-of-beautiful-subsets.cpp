class Solution {
public:
    int generate(vector<int>& nums,int ind, int k,int mask){
        int n=nums.size();
        if(ind==n) return mask>0 ? 1:0;
        bool isBeautiful=true;
        for(int i=0;i<ind && isBeautiful;i++){
            isBeautiful = ((1<<i)&mask) == 0 || abs(nums[i] - nums[ind]) != k;
        }
        int notpick = generate(nums,ind+1,k,mask);
        int pick;
        if(isBeautiful){
            pick = generate(nums,ind+1,k,mask+(1<<ind));
        }
        else pick =0;
        return notpick + pick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>subset;
        int n=nums.size();
        return generate(nums,0,k,0);
    }
};