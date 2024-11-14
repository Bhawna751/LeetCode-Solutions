class Solution {
public:
    bool bs(vector<int> arr,int target){
        int low=0, high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target)return true;
            else if(arr[mid] < target)low = mid+1;
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                return bs(matrix[i],target);
            }
        }   
        return false;
    }
};