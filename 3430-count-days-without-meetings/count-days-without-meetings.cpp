class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans=0, last=0;
        sort(meetings.begin(), meetings.end());
        for(auto it:meetings){
            int l =it[0], r = it[1];
            if(l > last + 1){
                ans += l - last - 1;
            }
            last = max(last, r);
        }
        ans += days - last;
        return ans;
    }
};