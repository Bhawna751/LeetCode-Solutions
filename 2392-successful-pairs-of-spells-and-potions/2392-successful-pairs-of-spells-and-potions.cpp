class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;//
        for(int i=0;i<n;i++){
            int l = 0, r = m-1;
            int ind = m;
            while(l<=r){
                int mid = l+(r-l)/2;//mid = 
                if((long long) spells[i]*potions[mid] >= success){
                    ind= mid;//ind = 2
                    r = mid-1;//r= 1
                }else{
                    l = mid+1;
                }
            }
            ans.push_back(m-ind);
        }
        return ans;
    }
};