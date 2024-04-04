class Solution {
public:
    int maxDepth(string s) {
        int ans=0,cnt=0;
        for( char c:s){
            if(c=='(')
                ans = max(ans,++cnt);
            if(c==')')
                cnt--;
        }
        return ans;
    }
};