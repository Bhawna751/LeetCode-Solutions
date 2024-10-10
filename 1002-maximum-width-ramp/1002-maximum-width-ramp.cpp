class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();//[6,0,8,2,1,5]
        vector<int> right(n);//8 8 8 5 5 5
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1], nums[i]);
        }
        int i=0,j=0;//i = 1, j = 3
        int maxi=0;// maxi = 2
        while(j<n){
            while(i<j && nums[i] > right[j])i++;
            maxi = max(maxi,j-i);
            j++;
        }
        return maxi;
    }
};