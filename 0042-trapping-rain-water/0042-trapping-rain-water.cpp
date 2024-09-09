class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax =0, rightMax = 0, left = 0, right = n-1, total = 0;
        while(left<right){
            if(height[left] <= height[right]){
                if(leftMax > height[left]){
                    total += leftMax - height[left];
                }
                else leftMax = height[left];
                left++;
            }
            else{
                if(rightMax > height[right]) total += rightMax - height[right];
                else rightMax = height[right];
                right--;
            }
        }
        return total;
    }
};