class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size(), i,j,k;
        stack<pair<string,int>> st;

        for(i=0;i<n;i++){
            char c = formula[i];
            if(isupper(c)){
                string it = "";
                it += c;
                for(j=i+1; j<n ;j++){
                    c = formula[j];
                    if(!islower(c)) break;
                    it += c;
                }
                string digit = "";
                for(k=j;k<n;k++){
                    c = formula[k];
                    if(!isdigit(c)) break;
                    digit += c;
                }
                if(digit == "") digit = "1";
                int d = stoi(digit);
                st.push({it,d});
                i=k-1;
            }
            else if(c == '('){
                st.push({"(",-1});
            }
            else if(c == ')'){
                string digit = "";
                for(j = i+1;j<n;j++){
                    c = formula[j];
                    if(!isdigit(c)) break;
                    digit += c;
                }
                if(digit == "") digit = "1";
                int d = stoi(digit);
                vector<pair<string,int>> temp;
                pair<string, int> op = {"(",-1};
                while(st.top() != op){
                    pair<string, int> p = st.top();
                    st.pop();
                    temp.push_back({p.first,p.second*d});
                }
                st.pop();
                while(temp.size()>0){
                    st.push(temp.back());
                    temp.pop_back();
                }
                i = j-1;
            }
        }
        map <string, int> mpp;
        while(!st.empty()){
            pair<string,int> p = st.top();
            st.pop();
            mpp[p.first] += p.second;
        }
        string ans = "";
        for(auto it : mpp){
            string e = it.first;
            string d = to_string(it.second);
            if(d=="1")d="";
            ans += e+d;
        }  
        return ans; 
    }
};