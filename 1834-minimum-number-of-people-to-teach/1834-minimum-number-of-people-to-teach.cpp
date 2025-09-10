class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = 500;

        vector<unordered_set<int>> personLang(languages.size());
        for (int i = 0; i < languages.size(); ++i)
            for (int lang : languages[i])
                personLang[i].insert(lang);

        vector<pair<int, int>> badPairs;
        for (auto& f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            bool canCommunicate = false;
            for (int lang : personLang[u])
                if (personLang[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            if (!canCommunicate)
                badPairs.push_back({u, v});
        }

        unordered_map<int, int> langCount;
        unordered_set<int> involvedPeople;

        for (auto& p : badPairs) {
            involvedPeople.insert(p.first);
            involvedPeople.insert(p.second);
        }

        for (int person : involvedPeople) {
            for (int lang : personLang[person])
                langCount[lang]++;
        }

        int maxCoverage = 0;
        for (auto& [lang, cnt] : langCount)
            maxCoverage = max(maxCoverage, cnt);

        return involvedPeople.size() - maxCoverage;
    }
};