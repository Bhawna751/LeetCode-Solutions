class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>ans(pq.size());
        int cnt=0;
        while(!pq.empty()){
            if(cnt==0){
                ans[pq.top().second] = "Gold Medal";
            }
            else if(cnt==1) ans[pq.top().second] = "Silver Medal";
            else if(cnt==2) ans[pq.top().second] = "Bronze Medal";
            else ans[pq.top().second] = to_string(cnt+1);
            cnt++;
            pq.pop();
        }
        return ans;
    }
};