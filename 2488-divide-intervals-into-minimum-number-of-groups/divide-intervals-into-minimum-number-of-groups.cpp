class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> interval;//(5,1)(11,-1)(6,1)(9,-1)(1,1)(6,-1)(2,1)(4,-1)(1,1)(11,-1)
        for(auto it: intervals){
            interval.push_back({it[0],1});
            interval.push_back({it[1]+1,-1});
        }
        sort(interval.begin(),interval.end());//(1,1)(1,1)(2,1)(4,-1)(5,1)(6,-1)(6,1)(9,-1)(11,-1)(11,-1)
        int cur=0, maxi=0;
        for(auto it: interval){
            cur += it.second;//cur = 0
            maxi = max(maxi, cur);//maxi = 3
        }
        return maxi;
    }
};