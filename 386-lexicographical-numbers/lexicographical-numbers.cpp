class Solution {
public:
    vector<int> lexicalOrder(int n) {//n =13
        int cur = 1;//cur = 10
        vector<int> ans;//1 10
        for(int i=0;i<n;i++){
            ans.push_back(cur);
            if(cur * 10 <= n) cur *= 10;
            else{
                while(cur%10 == 9 || cur>=n){
                    cur /= 10;
                }
                cur += 1;
            }
        }
        return ans;
    }
};