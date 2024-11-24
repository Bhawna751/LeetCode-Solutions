class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int mini = 1e9;
        int neg = 0;
        for(auto it: matrix){
            for(int val : it){
                ans += abs(val);
                if(val < 0)neg++;
                mini = min(mini,abs(val));
            }
        }   
        if(neg % 2 != 0)ans -= 2 * mini;
        return ans;
    }
};