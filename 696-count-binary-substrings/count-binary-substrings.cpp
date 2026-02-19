class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> cnt;
        int ans=0;
        int i=0;
        while(i<n){
            int j= i;
            if(s[i]=='0'){
                while(j<n && s[j]=='0')j++;
                cnt.push_back(j-i);
            }
            else{
                while(j<n && s[j]=='1')j++;
                cnt.push_back(j-i);
            }
            i=j;
        }
        for(int i=0;i<cnt.size()-1;i++){
            ans += min(cnt[i], cnt[i+1]);
        }
        return ans;
    }
};