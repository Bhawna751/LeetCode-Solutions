class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int dia = -1e9;
        int area = 0;
        for(auto it:dimensions){
            int d = pow(it[0],2) + pow(it[1],2);
            int cur = it[0] * it[1];
            if(d > dia) {
                dia = d;
                area = cur;
            }
            else if(d == dia) area = max(area, cur);
        }
        return area;
    }
};