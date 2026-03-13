class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int n = fruits.size();
        int i,j;
        for(i=0,j=0; j<n;j++){
            freq[fruits[j]]++;
            if(freq.size() > 2){
                if(--freq[fruits[i]]== 0){
                    freq.erase(fruits[i]);
                }
                i++;
            }
        }
        return j-i;
    }
};