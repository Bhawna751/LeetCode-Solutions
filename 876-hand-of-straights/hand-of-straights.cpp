class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize !=0) return false;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            int cur = mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp[cur+i] == 0) return false;
                mpp[cur+i]--;
                if(mpp[cur+i]<1) mpp.erase(cur+i);
            }
        }
        return true;
    }
};