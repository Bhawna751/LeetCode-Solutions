class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=0;
        int left=0, cur=0;
        for(int i=0;i<s.length();i++){
            cur += abs(s[i]-t[i]);
            while(cur>maxCost){
                cur = cur- abs(s[left]-t[left]);
                left++;
            }
            len = max(len,i-left+1);
        }
        return len;
    }
};