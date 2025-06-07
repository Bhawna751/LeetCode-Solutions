class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char>>pq;
        unordered_map<char, vector<int>> ind;
        vector<bool> valid(n, true);
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                char temp=pq.top();
                pq.pop();
                int last = ind[temp].back();
                ind[temp].pop_back();
                valid[i]=false;
                valid[last]=false;
            }
            else{
                pq.push(s[i]);
                ind[s[i]].push_back(i);
            }
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(valid[i]) ans += s[i];
        }
        return ans;
    }
};