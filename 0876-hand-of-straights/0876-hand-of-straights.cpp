class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        for(int i:hand)mpp[i]++;
        queue<int> start;
        int last=-1,opened=0;
        for(auto it: mpp){
            int i = it.first;
            if(opened > 0 && i >last+1 || opened>mpp[i])return false;
            start.push(mpp[i]-opened);
            last = i,opened=mpp[i];
            if(start.size()==groupSize){
                opened -=start.front();start.pop();
            }
        }
        return opened==0;
    }
};