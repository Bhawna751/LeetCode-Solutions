class Solution {
public:
    void helper(string& it, int &id, int &time, string &flag){
        int i=0;
        id =0;
        while(it[i] != ':') id = id * 10 + (it[i++]-'0');
        i++;
        flag = "";
        while(it[i]!=':') flag += it[i++];
        i++;
        time =0;
        while(i<it.size()) time = time * 10 + (it[i++] - '0');
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n,0);
        stack<int>st;
        int prev= 0;
        for(auto &it: logs){
            int id,time;
            string flag;
            helper(it, id, time, flag);
            if(flag == "start"){
                if(!st.empty()){
                    ans[st.top()] += time - prev;
                }
                st.push(id);
                prev = time;
            }
            else{
                ans[st.top()] += time - prev + 1;
                st.pop();
                prev = time+1;
            }
        }
        return ans;
    }
};