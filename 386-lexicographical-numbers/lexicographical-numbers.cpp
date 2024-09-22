class Solution {
private:
    void generate(int cur, int limit, vector<int> &ans){
        if(cur > limit) return ;
        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            int nxt = cur * 10 + i;
            if(nxt <= limit) generate(nxt,limit,ans);
            else break;
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1;i<=9;i++){
            generate(i,n,ans);
        }
        return ans;
    }
};