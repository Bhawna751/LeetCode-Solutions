class Solution {
public:
    
    string makeLargestSpecial(string s) {
       int n = s.size();//n=8
       if(n<=2)return s;
       int start = 0, cnt=0;//start = 0, cnt=0
        vector<string> str;//
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
            else cnt--;
            if(cnt==0){
                string inner  = s.substr(start+1, i-start-1);//inner ="10"
                str.push_back("1" + makeLargestSpecial(inner) + "0");//1(101100)0 --> 10 -->1100
                start = i+1;//start= 2
            }
        }
        sort(str.begin(), str.end(), greater<string>());//1100 10
        string ans;
        for (auto &it : str) ans += it;// ans= 110010
        return ans;//1(110010)0
    }
};