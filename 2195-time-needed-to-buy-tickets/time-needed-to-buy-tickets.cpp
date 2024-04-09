class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size(),time=0;
        while(true){
            for(int i=0;i<n;i++){
                if(tickets[i]==0)continue;
                tickets[i]--;
                ++time;
                if(tickets[k]==0)return time;
            }
        }
    }
};