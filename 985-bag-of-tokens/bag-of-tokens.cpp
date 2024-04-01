class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0,points=0,i=0,j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                power=power-tokens[i++];
                ans=max(ans,++points);
            }
            else if(points>0){
                points--;
                power+= tokens[j--];
            }
            else break;
        }
        return ans;
    }
};