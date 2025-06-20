class Solution {
public:
    int mann(int dist1, int dist2, int mod){
        return abs(dist1-dist2)+mod*2;
    }
    int maxDistance(string str, int k) {
        int n=0, e=0,w=0,s=0;
        int ans =0;
        for(char it:str){
            if(it == 'N')n++;
            else if(it == 'E')e++;
            else if(it == 'S')s++;
            else if(it == 'W')w++;
            int mod1 = min({n,s,k});
            int mod2 = min({e,w,k-mod1});
            ans=max(ans,mann(n,s,mod1)+mann(e,w,mod2));
        }
        return ans;
    }
};