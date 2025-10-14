class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int left = 0, right =0;
        for(char ch:s){
            if(ch == '('){
                left++;
                right++;
            }
            if(ch == ')') {
                right--;
                left = max(left-1,0);
            }
            if(ch == '*'){
                right++;
                left = max(left-1,0);
            }
            if(right<0)return false;
        }
        return left==0;
    }
};