class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n= skill.size(), total =0;
        vector<int> freq(1001,0);
        for(int it: skill){
            total += it;
            freq[it]++;
        }
        if(total % (n/2) != 0)return -1;
        int target = total / (n/2);
        long long chemistry = 0;
        for(int it: skill){
            int partner = target - it;
            if(freq[partner] == 0) return -1;
            chemistry += (long long)it * (long long)partner;
            freq[partner]--;
        }
        return chemistry/2;
    }
};