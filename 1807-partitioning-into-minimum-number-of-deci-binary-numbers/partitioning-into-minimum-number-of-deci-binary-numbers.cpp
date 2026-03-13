class Solution {
public:
    int minPartitions(string n) {
        //1 1 1 1 1
        //1 0 1 1 1/
        //1 0 1 1 1
        int ans=0;
        for(char c:n){
            ans = max(ans,c-'0');
        }
        return ans;
    }
};