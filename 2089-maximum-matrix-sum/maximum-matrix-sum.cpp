class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int mini = 1e9;
        int neg = 0;
        for(auto it: matrix){
            for(int val : it){
                ans += abs(val);//ans = 6
                if(val < 0)neg++;//neg = 0
                mini = min(mini,abs(val));//mini = 1
            }
        }   
        if(neg % 2 != 0)ans -= 2 * mini;
        return ans;
    }
};