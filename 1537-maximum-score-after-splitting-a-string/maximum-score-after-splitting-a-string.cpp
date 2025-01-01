class Solution {
public:
    int maxScore(string s) {
     int ans=0;
     for(int i=0;i<s.length()-1;i++){
        int cur=0;
        for(int j=0;j<=i;j++){
            if(s[j] == '0')cur++;
        }
        for(int j=i+1;j<s.length();j++){
            if(s[j] == '1')cur++;
        }
        ans = max(ans,cur);
     }   
     return ans;
    }
};