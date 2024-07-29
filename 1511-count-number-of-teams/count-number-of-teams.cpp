class Solution {
public:
    int cntInc(vector<int> &rating,int ind, int size, vector<vector<int>> &inc){
        int n=rating.size();
        if(ind == n)return 0;
        if(size == 3)return 1;
        if(inc[ind][size] != -1) return inc[ind][size];
        int teams = 0;
        for(int next = ind+1;next<n;next++){
            if(rating[next] > rating[ind]){
                teams += cntInc(rating,next,size+1,inc);
            }
        }
        return inc[ind][size] = teams;
    }

    int cntDec(vector<int> &rating,int ind, int size, vector<vector<int>> &dec){
        int n=rating.size();
        if(ind == n)return 0;
        if(size == 3)return 1;
        if(dec[ind][size] != -1) return dec[ind][size];
        int teams = 0;
        for(int next = ind+1;next<n;next++){
            if(rating[next] < rating[ind]){
                teams += cntDec(rating,next,size+1,dec);
            }
        }
        return dec[ind][size] = teams;
    }

    int numTeams(vector<int>& rating) {
        int n =rating.size(), team = 0;
        vector<vector<int>> inc(n,vector<int>(4,-1));
        vector<vector<int>> dec(n,vector<int>(4,-1));
        for(int i = 0;i<n;i++){
            team += cntInc(rating,i,1,inc) + cntDec(rating,i,1,dec); 
        }
        return team;
    }
};