class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> pos;
        for(auto it:factory){
            for(int i=0;i<it[1];i++){
                pos.push_back(it[0]);
            }
        }
        int cnt = robot.size(), factcnt = pos.size();
        vector<vector<long long>> memo(cnt, vector<long long>(factcnt,-1));
        return solve(0,0,robot,pos,memo);
    }
    long long solve(int rind,int find, vector<int>&robot, vector<int>&pos, vector<vector<long long>> &memo){
        if(rind == robot.size()) return 0;
        if(find == pos.size())return 1e12;
        if(memo[rind][find] != -1) return memo[rind][find];
        long long  assign = abs(robot[rind] - pos[find]) + solve(rind+1, find+1, robot, pos,memo);
        long long  skip = solve(rind, find+1, robot, pos,memo);
        return memo[rind][find] = min(assign, skip);
    }
};