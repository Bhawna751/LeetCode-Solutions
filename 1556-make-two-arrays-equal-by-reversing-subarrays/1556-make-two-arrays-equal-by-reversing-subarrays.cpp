class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> arrfreq;
        for (int it : arr) {
            arrfreq[it]++;
        }
        unordered_map<int, int> targetfreq;
        for (int it : target) {
            targetfreq[it]++;
        }
        if (targetfreq.size() != arrfreq.size())
            return false;
        for (auto it : arrfreq) {

            if (targetfreq[it.first] != it.second)
                return false;
        }
        return true;
    }
};