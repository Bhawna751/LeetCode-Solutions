class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        /*
            0 1
            1 0
            0 -1
            -1 0
        */
        vector<vector<int>> traversed;
        /*
            1,4
            1,5

        */
        for(int st=1,d=0;traversed.size()<rows*cols;){
            for(int i=0;i<2;i++){
                for(int j=0;j<st;j++){
                    if(rStart >=0 && rStart < rows && cStart >=0 && cStart < cols){
                        traversed.push_back({rStart,cStart});
                    }
                    rStart += dir[d][0];//rstart = 1
                    cStart += dir[d][1];//cstart = 5
                }
                d = (d + 1)%4;//d=1
            }
            ++st;//st=2
        }
        return traversed;
    }
};