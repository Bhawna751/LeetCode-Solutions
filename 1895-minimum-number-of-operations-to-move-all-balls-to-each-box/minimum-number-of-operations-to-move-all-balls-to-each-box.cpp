class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length());
        for(int cur=0;cur<boxes.length();cur++){
            if(boxes[cur] == '1'){
                for(int j=0;j<boxes.length();j++){
                    ans[j]+=abs(j-cur);
                }
            }
        }
        return ans;
    }
};