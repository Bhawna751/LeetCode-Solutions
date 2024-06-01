class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;//hello
        for(int i=0;i<s.length()-1;i++){//0-->3 1
            sum += abs(s[i]-s[i+1]);//sum = 3 + 7
        }
        return sum;
    }
};