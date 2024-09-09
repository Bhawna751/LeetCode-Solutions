class Solution {
public:
    vector<int> prefix(vector<int> &height, int n){
        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],height[i]);
        }
        return prefixMax;
    }
    vector<int> suffix(vector<int> &height, int n){
        vector<int> suffixMax(n);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }
        return suffixMax;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left = prefix(height,n), right=suffix(height,n);
        int total =0;
        for(int i=0;i<n;i++){
            if(left[i] > height[i] && right[i] > height[i]){
                total += min(left[i],right[i]) - height[i];
            }
        }
        return total;
    }
};