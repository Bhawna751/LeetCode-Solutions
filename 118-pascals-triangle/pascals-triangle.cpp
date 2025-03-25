class Solution {
public:
    vector<int> pattern(int ind){
        vector<int> row;
        int sum = 1;
        row.push_back(1);
        for(int i=1;i<ind;i++){
            sum *= (ind - i);
            sum /= i;

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