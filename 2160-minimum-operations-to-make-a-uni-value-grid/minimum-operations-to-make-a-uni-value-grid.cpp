class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] % x != grid[0][0] % x) return -1;
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int n=  nums.size();
        int left=0, right=n-1;
        while(left<right){
            if(left<n-right-1){
                int leftOp = (left+1)*(nums[left+1]-nums[left])/x;
                ans += leftOp;
                left++;
            }
            else{
                int rightOp = (n-right)*(nums[right]-nums[right-1])/x;
                ans += rightOp;
                right--;
            }
        }
        return ans;
    }
};