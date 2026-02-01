class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return accumulate(nums.begin(), nums.end(),0);
        int x=51, y=51;
        for(int i=1;i<n;i++){
            if(nums[i] < x){
                y = x;// x = 2
                x= nums[i];
            }else if(nums[i] < y){ //y = 3
                y = nums[i];
            }
            if(x==1 && y==1)break;
        }
        return nums[0] + x + y;
    }
};