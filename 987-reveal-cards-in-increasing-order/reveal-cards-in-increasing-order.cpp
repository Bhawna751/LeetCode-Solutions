class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        if(n==1)return deck;
        queue<int>q;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int i=0;i<n;i++){
            res[q.front()]=deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};