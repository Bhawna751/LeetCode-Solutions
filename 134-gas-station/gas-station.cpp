class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start =0, total=0, cur=0;
        for(int i=0;i<gas.size();i++){
            int fuel = gas[i] - cost[i];
            total += fuel;
            cur += fuel;
            if(cur<0){
                cur=0;
                start = i+1;
            }
        }
        return total<0 ? -1 : start;
    }
};