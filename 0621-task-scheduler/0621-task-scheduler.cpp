class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>count;
        for(char t:tasks){
            count[t]++;
        }
        priority_queue<pair<int,char>>pq;
        for(pair<char,int>cnt:count){
            pq.push(make_pair(cnt.second,cnt.first));
        }
        int alltime=0,cycle=n+1;
        while(!pq.empty()){
            int time=0;
            vector<pair<int,char>> tmp;
            for(int i=0;i<cycle;i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top());
                    pq.pop(); time++;
                }
            }
            for(auto t:tmp){
                if(--t.first){
                    pq.push(t);
                }
            }
            alltime+= !pq.empty()?cycle:time;
        }
        return alltime;
    }
};