class Solution {
public:
    int maxElement(vector<vector<int>> &mat, int col){
        int n=mat.size(), val  =-1e9, ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > val){
                val = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row = maxElement(mat,mid);
            int left = mid-1 >= 0 ? mat[row][mid-1] : -1e9;
            int right = mid+1 < m ? mat[row][mid+1] : -1e9; 
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(mat[row][mid] < left)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};