class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
            int l =0, r=potions.size()-1;
            int ind = potions.size();
            while(l<=r){
                int mid = (l+r)/2;
                if((long long) spells[i]*potions[mid] >=success){
                    ind = mid;
                    r = mid-1;
                }else l = mid + 1;
            }
            ans.push_back(potions.size()-ind);
        }
        return ans;
    }
};