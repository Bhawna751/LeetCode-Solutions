class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize !=0) return false;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        for(int it : hand){
            int start = it;
            while(mpp[start-1]) start--;
            while(start <= it){
                while(mpp[start]){
                    for(int next = start; next< start+ groupSize;next++){
                        if(!mpp[next]) return false;
                        mpp[next]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};