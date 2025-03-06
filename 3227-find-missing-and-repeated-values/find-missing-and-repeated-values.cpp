class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0;
        long long sqr = 0;
        long long n = grid.size();
        long long total = n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                sqr += grid[i][j] * grid[i][j];
            }
        }
        long long sdiff = sum - total * (total+1)/2;
        long long sqrdiff = sqr - total * (total+1)*(2*total+1)/6;
        int a = (sqrdiff / sdiff + sdiff)/2;
        int b = (sqrdiff / sdiff - sdiff)/2;
        return {a,b};
    }
};