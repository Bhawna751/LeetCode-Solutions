class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m=mat[0].size();// [[1,2,3],[4,5,6],[7,8,9]]
        int d = 0;
        int i=0,j=0;
        vector<int> ans;//1
        while(i<n && j<m){
            ans.push_back(mat[i][j]); 
            int nr, nc;
            if(d == 0){
                nr = i - 1;// nr = -1
                nc = j + 1;// nc = 1
            }
            else {
                nr = i + 1;
                nc = j - 1;
            }
            if(nr < 0 || nr == n || nc < 0 || nc == m){
                if(d==0){
                    if(j == m-1) i++;
                    if(j < m-1) j++;
                }else{
                    if(i == n-1) j++;
                    if(i < n-1) i++;
                }
                d = !d;
            }
            else{
                i = nr;//i = -1
                j = nc;//j = 1
            }
        }
        return ans;

    }
};