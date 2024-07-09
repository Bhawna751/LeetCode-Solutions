class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
       int idle=0;
       long long wt=0;
       for(int i=0;i<customers.size();i++){
            idle = max(customers[i][0],idle) + customers[i][1];
            wt += idle - customers[i][0];
       } 
       double avg = (double)(wt)/customers.size();
       return avg;
    }
};