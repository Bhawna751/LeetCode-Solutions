class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);//1101057
        set<char> digits(n.begin(),n.end());//0 1 5 7
        int maxi = num, mini=num;
        for(char it: digits){
            for(char i = '0';i <= '9'; i++){
                if(n[0] == it && i == '0') continue;
                string newStr = n;
                replace(newStr.begin(), newStr.end(),it,i);
                int newNum = stoi(newStr);
                maxi = max(maxi, newNum);
                mini = min(mini,newNum);
            }
        }
        return maxi-mini;
    }
};