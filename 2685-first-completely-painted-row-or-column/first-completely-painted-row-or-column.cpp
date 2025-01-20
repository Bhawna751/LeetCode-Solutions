class Solution {
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<int> rcnt(n), ccnt(m);

        unordered_map<int,pair<int,int>>  mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = mat[i][j];
                mpp[val] = {i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            int it = arr[i];
            auto [r,c] = mpp[it];
            rcnt[r]++;
            ccnt[c]++;
            if(rcnt[r] == m || ccnt[c] == n) return i;
        }
        return -1;
    }
};