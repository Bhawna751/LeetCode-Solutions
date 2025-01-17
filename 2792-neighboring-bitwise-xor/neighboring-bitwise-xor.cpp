class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for(int it:derived) xorr ^= it;
        return xorr == 0;
    }
};