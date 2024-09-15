class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string ans = "";
        int cnt=0;
        while(ans.size() < b.size()){
            ans += a;
            cnt++;
        }
        if(ans.find(b) != string::npos) return cnt;
        ans+=a;
        cnt++;
        if(ans.find(b) != string::npos) return cnt;
        return -1;
    }
};