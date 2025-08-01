class Solution {
public:
    vector<int> pattern(int n){
        int sum=1;
        vector<int> row;
        row.push_back(1);
        for(int i=1;i<n;i++){
            sum = sum * (n-i);
            sum = sum / i;
            row.push_back(sum);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1;i<=numRows;i++){
            ans.push_back(pattern(i));
        }
        return ans;
    }
};