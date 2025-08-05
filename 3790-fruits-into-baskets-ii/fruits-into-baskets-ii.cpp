class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt =0, n = baskets.size();
        for(auto it: fruits){
            for(auto &b: baskets){
                if(it<=b){
                    b=0;
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};