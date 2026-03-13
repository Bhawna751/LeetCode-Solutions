class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans=-1;
        int l=0,h=0;
        int cnt=0;
        unordered_map<char,int>mpp;

        while(h<n){
            mpp[s[h]]++;
            cnt=max(cnt, mpp[s[h]]);
            if((h-l+1)-cnt > k){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans, h-l+1);
            h++;
        }
        return ans;
    }
};