class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> cnt(1024);
        long long ans =0,cur=0;
        cnt[0]=1L;
        for(char &c:word){
            cur ^=1<<(c-'a');
            ans += cnt[cur]++;
            for(int i=0;i<10;i++){
                int search = cur^(1<<i);
                ans+= cnt[search];
            }
        }
        return ans;
    }
};