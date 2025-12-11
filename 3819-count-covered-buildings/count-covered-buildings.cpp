class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans=0;
        unordered_map<int,vector<int>>row;
        unordered_map<int,vector<int>>col;

        for(auto &it:buildings){
            int x=it[0],y=it[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }
        for(auto &it:row)sort(it.second.begin(),it.second.end());
        for(auto &it:col)sort(it.second.begin(),it.second.end());

        for(auto &it:buildings){
            int x=it[0],y=it[1];
            auto &r = row[x], &c=col[y];

            int posr = lower_bound(r.begin(),r.end(),y) - r.begin();
            int posc = lower_bound(c.begin(),c.end(),x) - c.begin();

            bool l=(posr>0);
            bool right=(posr+1<r.size());
            bool u=(posc>0);
            bool d=(posc+1<c.size());
            
            if(u && d && l && right)ans++;
        }
        return ans;
    }
};