class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        int max_fr=0,cntmaxfr=0,sz=tasks.size();
        for(char i :tasks){
            mp[i-'A']++;
            if(mp[i-'A']>max_fr){
                max_fr=mp[i-'A'];
            }
        }
        for(int i =0;i<26;i++){
            if(mp[i]==max_fr)cntmaxfr++;
        }
        int time  = (max_fr-1)*(n+1)+cntmaxfr;
        return max(time,sz);
    }
};