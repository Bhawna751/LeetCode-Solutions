class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = skill.size(), m = mana.size();
    vector<long long> completed(n + 1);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i)
            completed[i + 1] = max(completed[i + 1], completed[i]) + mana[j] * skill[i];
        for (int i = n - 1; i > 0; --i)
            completed[i] = completed[i + 1] - mana[j] * skill[i];     
    }
    return completed.back();
}
};