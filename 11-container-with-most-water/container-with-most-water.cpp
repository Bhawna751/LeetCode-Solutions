class Solution {
public:
    int maxArea(vector<int>& height) {// [1,8,6,2,5,4,8,3,7]
        int maxi = 0, left = 0, right = height.size()-1;// left = 1 right = 7
        while(left < right){
            maxi = max(maxi, (right - left) * min(height[left], height[right]));// maxi = 49
            if(height[left] <  height[right]) left++;
            else right--;
        }
        return maxi;
    }
};