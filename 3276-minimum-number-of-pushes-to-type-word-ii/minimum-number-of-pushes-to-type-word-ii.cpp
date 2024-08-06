class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        /* 
            a-> 2
            b-> 2
            c-> 2
            d-> 2
            e-> 2
            f-> 2 
            g-> 2
            h-> 2
            i-> 6
        */
        for(auto it:word) ++freq[it];
        priority_queue<int> pq;//    2 
        for(auto it: freq) pq.push(it.second);
        int total = 0, ind=0;// total = 18   ind = 7
        while(!pq.empty()){
            total += (1+ (ind/8)) * pq.top();
            pq.pop();
            ind++;
        }
        return total;
    }
};