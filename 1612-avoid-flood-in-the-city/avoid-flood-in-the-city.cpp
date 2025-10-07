class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n,-1);
        set<int>sunny;
        unordered_map<int,int> lastRained;
        for(int i=0;i<n;i++){
            int lake = rains[i];
            if(lake > 0){
                if(lastRained.count(lake)){
                    auto sunnyDay = sunny.upper_bound(lastRained[lake]);
                    if(sunnyDay == sunny.end()) return {};
                    ans[*sunnyDay] = lake;
                    sunny.erase(sunnyDay);
                }
                lastRained[lake]=i;
            }else{
                sunny.insert(i);
                ans[i]=1;
            }
        }
        return ans;
    }
};