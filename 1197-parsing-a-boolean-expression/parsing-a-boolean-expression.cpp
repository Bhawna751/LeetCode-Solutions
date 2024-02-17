class Solution {
public:
    int mod =100000007;
    long long f(int i,int j,int isTrue,string &exp){
        if(i>j)return 0;
        if(i==j){
            if(isTrue){
                return exp[i] == 'T' ? 1:0;

            }
            else{
                return exp[i] == 'F' ? 1:0;
            }
        }
        long long way=0;
        for(int ind=i+1;ind<=j-1;ind+=2){
            long long lt = f(i,ind-1,1,exp);
            long long lf = f(i,ind-1,0,exp);
            long long rt = f(ind+1,j,1,exp);
            long long rf = f(ind+1,j,0,exp);
            if(exp[ind]=='&'){
                if(isTrue) way = (way + (rt*lt)%mod)%mod;
                else way = (way + (rt*lf)%mod+(rf & lt)%mod + (rf & lf) %mod)%mod;
            }
            else if(exp[ind] == '|'){
                if(isTrue){
                    way = (way + (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod) %mod;
                }
                else{
                    way = (way + (rf*lf)%mod)%mod;
                }
            }
            else{
                if(isTrue){
                    way = (way+ (lt*rf)%mod + (lf*rt)%mod)%mod;
                }
                else{
                    way = (way + (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod) %mod;
                }
            }
        }
        return way;
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(auto it : expression){
            if(it==')'){
                auto t = false,f = false;
                while(st.top()=='t' || st.top()=='f'){
                    t |= st.top() == 't';
                    f |= st.top() == 'f';
                    st.pop();
                }
                auto op = st.top();
                st.pop();
                st.push(op == '!' ? f ? 't' : 'f' : op == '&' ? !f ? 't' : 'f' : t ? 't' : 'f');

            }
            else if(it != ',' && it != '(')st.push(it);
        }
        return st.top() == 't' ? true : false;
    }
};