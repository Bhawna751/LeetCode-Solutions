class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;//Push Push Pop
        int cnt=1;//cnt = 3
        for(int i=0;i<target.size();i++){
            if(cnt == target[i]){
                ans.push_back("Push");
                cnt++;
                continue;
            }
            else{
                while(cnt != target[i]){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    cnt++;
                }
                if(cnt == target[i]){
                    ans.push_back("Push");
                    cnt++;
                }
            }
        }
        return ans;
    }
};