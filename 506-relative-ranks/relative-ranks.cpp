class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int>mpp;
        priority_queue<int> pq;
        vector<string>ans;

        for(int i=0;i<score.size();i++){
            pq.push(score[i]);
        }
        int cnt=1;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            mpp[ele]=cnt++;
        }

        for(auto it:score){
            int rank = mpp[it];
            if(rank==1)ans.push_back("Gold Medal");
            else if(rank==2)ans.push_back("Silver Medal");
            else if(rank==3)ans.push_back("Bronze Medal");
            else ans.push_back(to_string(rank));
        }
        return ans;
    }
};