class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int n = customers.size();// 1 0 1 2 1 1 7 5
        int unsatisfied=0;// grumpy 0 1 0 1 0 1 0 1
        for(int i=0;i<m;i++){
            unsatisfied += customers[i]*grumpy[i];//unsatisfied = 0
        }
        int maxUnsatisfied = unsatisfied;
        //sliding window
        for(int i=m;i<n;i++){
            unsatisfied += customers[i] * grumpy[i];//6
            unsatisfied -= customers[i-m] * grumpy[i-m];//6
            maxUnsatisfied = max(maxUnsatisfied, unsatisfied);//maxunsatisfied = 6
        }
        int total = maxUnsatisfied;
        for(int i=0;i<n;i++){
            total += customers[i]*(1-grumpy[i]);//total = 6 + 1 + 1 + 1 + 7 = 16
        }
        return total;
    }
};