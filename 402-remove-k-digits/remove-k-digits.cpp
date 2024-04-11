class Solution {
public:
    string removeKdigits(string num, int k) {
       if (num.length()<=k) return "0";
       if(k==0) return num;
       string ans = "";
       stack<char>s;
       s.push(num[0]);
       for(int i=1;i<num.length();++i){
           while(k>0 && !s.empty()&&num[i]<s.top()){
               --k;
               s.pop();
           }
           s.push(num[i]);
           if(s.size()==1 && num[i]=='0') s.pop();
       }
       while(k && !s.empty()){
           --k;s.pop();
       }
       while(!s.empty()){
           ans.push_back(s.top());
           s.pop();
       }
       reverse(ans.begin(),ans.end());
       if(ans.length()==0)return "0";
       return ans;

    }
};