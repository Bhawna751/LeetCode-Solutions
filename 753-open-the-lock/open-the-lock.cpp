class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ds(deadends.begin(),deadends.end());
        unordered_set<string> vis;
        int res=0;
        if(ds.find("0000")!=ds.end()) return -1;
        queue<string> wheel;
        wheel.push("0000");
        vis.insert("0000");
        while(!wheel.empty()){
            int level = wheel.size();
            while(level--){
                string up,down,cur=wheel.front();
                wheel.pop();
                if(cur==target) return res;
                for(int i=0;i<4;i++){
                    down=up=cur;
                    char upc=up[i], downc=down[i];
                    up[i] = (upc == '9' ? '0' : upc+1);
                    down[i] = (downc == '0' ? '9' : downc-1);
                    if(vis.find(up) == vis.end() && ds.find(up)==ds.end()){
                        wheel.push(up);
                        vis.insert(up);
                    }
                    if(vis.find(down) == vis.end() && ds.find(down)==ds.end()){
                        wheel.push(down);
                        vis.insert(down);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};