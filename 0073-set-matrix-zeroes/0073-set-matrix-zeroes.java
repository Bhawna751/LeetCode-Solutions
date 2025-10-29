class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length, m=matrix[0].length;
        boolean firstcolzero = false;
        boolean firstrowzero = false;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                firstcolzero=true;
                break;
            }
        }
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                firstrowzero=true;
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(firstcolzero){
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }
        if(firstrowzero){
            for(int j=0;j<m;j++) matrix[0][j]=0;
        }
    }
}