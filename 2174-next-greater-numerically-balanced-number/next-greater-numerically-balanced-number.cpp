class Solution {
public:
    void solve(long num,vector<int>&cnt, vector<int>& list){
        if (num > 0 && isBeautiful(cnt)) {
            list.push_back((int)num);
        }
        if (num > 1224444) return;

        for (int d = 1; d <= 7; ++d) {
            if (cnt[d] < d) {
                cnt[d]++;
                solve(num * 10 + d, cnt, list);
                cnt[d]--;
            }
        }
    }
     bool isBeautiful(const vector<int>& count) {
        for (int d = 1; d <= 7; ++d) {
            if (count[d] != 0 && count[d] != d)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        vector<int>list,cnt(10,0);
        solve(0,cnt,list);
        sort(list.begin(), list.end());
        for(int it:list) if(it>n)return it;
        return -1;
    }
};