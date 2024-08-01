class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(string it: details){
            int age = stoi(it.substr(11,2));
            if(age > 60 ){
                ans++;
            }
        }
        return ans;
    }
};