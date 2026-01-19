class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int ans=0;
        int i,j;
        vector<vector<int>>copy(n+1,vector<int>(m+1,0));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                copy[i][j]=copy[i][j-1] + mat[i-1][j-1] + copy[i-1][j] - copy[i-1][j-1];
            }
        }
        int l=1,h=min(n,m);
        while(l<=h){
            int mid = (l+h)/2;
            bool flag=0;
            for(i=mid;i<n+1;i++){
                for(j=mid;j<m+1;j++){
                    if(copy[i][j] - copy[i][j-mid] - copy[i-mid][j] + copy[i-mid][j-mid] <= threshold){
                        l=mid+1;
                        ans=mid;
                        flag=1;
                        break;
                    }
                }
                if(flag==1)break;
            }
            if(flag==0)h=mid-1;
        }
        return ans;

    }
};