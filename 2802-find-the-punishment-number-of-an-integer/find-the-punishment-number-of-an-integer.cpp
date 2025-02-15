class Solution {
public:
    bool partitions(int ind, int sum, string num, int target, vector<vector<int>>&memo){
        if(ind == num.size())return sum == target;
        if(sum > target)return false;
        if(memo[ind][sum] != -1)return memo[ind][sum];
        bool partitioned = false;
        for(int i=ind;i<num.size();i++){
            string cur = num.substr(ind,i-ind+1);
            int add = stoi(cur);
            partitioned = partitioned || partitions(i+1,sum+add,num,target,memo);
            if(partitioned == true)return true;
        }
        return memo[ind][sum]=partitioned;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i =1;i<= n ;i++){
            int sq = i*i;
            string num = to_string(sq);
            vector<vector<int>> memo(num.size(),vector<int>(i+1,-1));
            if(partitions(0,0,num,i,memo)) ans += sq;
        }
        return ans;
    }
};