class Solution {
public:
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());//0 1 4 4 5 7
        long long l=0,h=0;
        for(int i=0,j=nums.size()-1;i<j;i++){
            while(i<j && nums[i]+nums[j]>lower-1){
                j--;
            }
            l += j-i;//5
        }
        for(int i=0,j=nums.size()-1;i<j;i++){
            while(i<j && nums[i]+nums[j]>upper){
                j--;
            }
            h += j-i;
        }
        return h-l;
    }
};