class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mpp;
        int ans=0;
        for(int it:answers){
            mpp[it]++;
        }
        for(auto it: mpp){
            ans+= ceil((double)it.second/(it.first+1)) * (it.first+1);
        }
        return ans;
    }
};