class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int cur = 1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(cur);
            if(cur * 10 <= n) cur *= 10;
            else{
                while(cur % 10 == 9 || cur >=n)cur /= 10;
                cur++;
            }
        }
        return ans;
    }
};