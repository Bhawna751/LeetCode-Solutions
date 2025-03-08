class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        queue<char> q;
        int whites=0;
        while(q.size()<k){
            char cur = blocks[q.size()];
            if(cur == 'W')whites++;
            q.push(cur);
        }
        int ans= whites;
        for(int i=k;i<n;i++){
            if(q.front() == 'W') whites--;
            q.pop();
            if(blocks[i] == 'W') whites++;
            q.push(blocks[i]);
            ans = min(ans,whites);
        }
        return ans;
    }
};