class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cnt = it.first;
            char ch = it.second;
            if(ans.length() >= 2 && ans[ans.length()-1] == it.second && ans[ans.length()-2] == it.second){
                if(pq.empty()) break;
                auto temp = pq.top();
                pq.pop();
                ans += temp.second;
                if(temp.first - 1 > 0) pq.push({temp.first-1, temp.second});
            } else{
                cnt--;
                ans += ch;
            }
            if(cnt > 0){
                pq.push({cnt,ch});
            }
        }
        return ans;
    }
};