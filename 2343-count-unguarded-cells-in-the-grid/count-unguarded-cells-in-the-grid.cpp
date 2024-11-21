class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(auto it: guards)mat[it[0]][it[1]]=-1;
        for(auto it: walls)mat[it[0]][it[1]]=-2;   
        /*
            0  0  0  0
            0  0  0  0
            
        */
        for(int i=0;i<m;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1)flag=false;
                else if(mat[i][j]==-2)flag=true;
                else
                    if(flag)mat[i][j]++;
            }
        }
        for(int j=0;j<n;j++){
            bool flag=true;
            for(int i=0;i<m;i++){
                if(mat[i][j]==-1)flag=false;
                else if(mat[i][j]==-2)flag = true;
                else 
                    if(flag)mat[i][j]++;
            }
        }
        for(int i=m-1;i>=0;i--){
            bool flag=true;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==-1)flag=false;
                else if(mat[i][j]==-2)flag = true;
                else 
                    if(flag)mat[i][j]++;
            }
        }
        for(int j=n-1;j>=0;j--){
            bool flag=true;
            for(int i=m-1;i>=0;i--){
                if(mat[i][j]==-1)flag=false;
                else if(mat[i][j]==-2)flag = true;
                else 
                    if(flag)mat[i][j]++;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 4) ans++;
            }
        }
        return ans;
    }
};