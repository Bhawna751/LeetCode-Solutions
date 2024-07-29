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
        vector<vector<int>> inc(n,vector<int>(4,0));
        vector<vector<int>> dec(n,vector<int>(4,0));
        for(int i = 0;i<n;i++){
            inc[i][1]=1;
            dec[i][1]=1;
        }
        for(int cnt = 2;cnt<=3;cnt++){
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(rating[j] > rating[i])
                        inc[j][cnt] += inc[i][cnt-1];
                    if(rating[j] < rating[i])
                        dec[j][cnt] += dec[i][cnt-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            team += inc[i][3] + dec[i][3];
        }
        return team;
    }
};