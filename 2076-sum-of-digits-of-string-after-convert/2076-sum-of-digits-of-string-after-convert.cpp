class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char ch:s){
            num += to_string(ch - 'a' + 1);
        }
        while(k>0){
            int sum = 0;
            for(char ch : num){
                sum += ch - '0';
            }
            num = to_string(sum);
            k--;
        }
        return stoi(num);
    }
};