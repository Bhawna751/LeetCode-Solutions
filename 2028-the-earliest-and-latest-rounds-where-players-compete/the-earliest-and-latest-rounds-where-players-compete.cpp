class Solution {
public:
    int f, s, n;
    int maxr = INT_MIN, minr = INT_MAX;
    vector<int> earliestAndLatest(int N, int F, int S) {
        f = F-1, s = S-1, n = N;
        string players = string(n, '1');
		int round = 1, left = 0, right = n-1;
        help(players, left, right, round);
        return {minr, maxr};
    }
    
    void help(string &players, int l, int r, int round){
        if(l >= r){
            help(players, 0, n-1, round+1);
        }
        else if(players[l] == '0'){
            help(players, l+1, r, round);
        }
        else if(players[r] == '0'){
            help(players, l, r-1, round);
        }
        else if((l == f and r == s) or (l == s and r == f)){
            minr = min(minr, round);
            maxr = max(maxr, round);
        }
        else if(l == f || l == s){
            players[r] = '0';
            help(players, l+1, r-1, round);
            players[r] = '1';
        }
        else if(r == f || r == s){
            players[l] = '0';
            help(players, l+1, r-1, round);
            players[l] = '1';
        }
        else{
            players[r] = '0';
            help(players, l+1, r-1, round);
            players[r] = '1';
            players[l] = '0';
            help(players, l+1, r-1, round);
            players[l] = '1';
        }
    }
};