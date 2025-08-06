class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = sqrt(n);
        int block = (n+m-1)/m;
        int cnt = 0;
        vector<int> maxi(block);
        for(int i=0;i<n;i++){
            maxi[i/m] = max(maxi[i/m], baskets[i]);

        }
        for(auto it: fruits){
            int i;
            int unplaced=1;
            for(i=0;i<block;i++){
                if(maxi[i]<it)continue;
                int flag=0;
                maxi[i]=0;
                for(int j=0;j<m;j++){
                    int pos = i*m+j;
                    if(pos < n && baskets[pos] >= it && !flag){
                        baskets[pos]=0;
                        flag=1;
                    }
                    if(pos<n){
                        maxi[i] = max(maxi[i], baskets[pos]);
                    }
                }
                unplaced=0;
                break;
            }
            cnt += unplaced;
        }
        return cnt;
    }
};