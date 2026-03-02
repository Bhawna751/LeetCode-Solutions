class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zeroCnt(n);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j = n-1;j>=0 && grid[i][j]==0;j--){
                cnt++;
            }
            zeroCnt[i] = cnt;
        }
        int op =0 ;
        for(int i=0;i<n;i++){
            int req = n-i-1;
            int ind = i;
            while(ind < n && zeroCnt[ind] < req) ind++;
            if (ind == n) return -1;
            while (ind > i) {
                zeroCnt[ind] = zeroCnt[ind - 1];
                ind--;
                op++;
            }
            zeroCnt[i] = req;
        }
        return op;
    }
};