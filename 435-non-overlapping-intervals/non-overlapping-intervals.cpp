    bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans=-1;
        sort(intervals.begin(), intervals.end(),comp);
        vector<int> prev = intervals[0];
        for(auto it:intervals){
            if(prev[1]>it[0]) ans++;
            else prev=it;
        }
        return ans;
    }
};