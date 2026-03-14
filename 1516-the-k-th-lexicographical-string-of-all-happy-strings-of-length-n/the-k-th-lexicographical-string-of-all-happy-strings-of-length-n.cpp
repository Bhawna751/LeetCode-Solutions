class Solution {
public:
    void generate(int n , vector<string>& happy, string cur){
        if(cur.size()==n){
            happy.push_back(cur);
            return ;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(cur.size()>0 && cur.back()==ch)continue;
            generate(n, happy, cur+ch);
        }
    }
    string getHappyString(int n, int k) {
        string cur="";
        vector<string> happy;
        generate(n,happy, cur);
        if(happy.size()<k) return "";
        sort(happy.begin(), happy.end());
        return happy[k-1];
    }
};