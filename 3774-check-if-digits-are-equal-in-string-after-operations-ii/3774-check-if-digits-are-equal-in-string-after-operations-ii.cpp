
class Solution {
public:
    unordered_map<int, int> modularInverses = {
        {1, 1},
        {3, 7},
        {7, 3},
        {9, 9},
    };
    tuple<int, int, int> mult(tuple<int, int, int> a, tuple<int, int, int> b) {
        return {get<0>(a) + get<0>(b), get<1>(a) + get<1>(b),
                (get<2>(a) * get<2>(b)) % 10};
    }
    tuple<int, int, int> div(tuple<int, int, int> a, tuple<int, int, int> b) {
        return {get<0>(a) - get<0>(b), get<1>(a) - get<1>(b),
                (get<2>(a) * modularInverses[get<2>(b)]) % 10};
    }
    int red(vector<pair<int, int>> it) {
        int sum = 0;
        for (auto& p : it) {
            sum = (sum + (p.first * p.second) % 10) % 10;
        }
        return sum;
    }

    vector<int> TWOS = {2, 4, 8, 6};
    vector<int> FIVES = {5};

    int simplify(tuple<int, int, int> tup) {
        int twos = get<0>(tup);
        int fives = get<1>(tup);
        int res = get<2>(tup);

        if (twos)
            res = (res * TWOS[(twos - 1) % TWOS.size()]) % 10;
        if (fives)
            res = (res * FIVES[(fives - 1) % FIVES.size()]) % 10;

        return res;
    }
    bool hasSameDigits(string s) {
        int n = s.size() - 2;
        vector<tuple<int, int, int>> facts;
        facts.push_back({0, 0, 1});
        while (n >= (int)facts.size()) {
            int num = facts.size();
            int twos = 0;
            while (num % 2 == 0) {
                num /= 2;
                twos++;
            }
            int fives = 0;
            while (num % 5 == 0) {
                num /= 5;
                fives++;
            }
            facts.push_back(mult(facts.back(), {twos, fives, num}));
        }
        vector<int> pascal;
        for (int k = 0; k <= n; k++) {
            auto temp = div(facts[n], facts[k]);
            temp = div(temp, facts[n - k]);
            pascal.push_back(simplify(temp));
        }

        vector<pair<int, int>> zipped1, zipped2;
        for (int i = 0; i < s.size(); i++)
            if (i <= n)
                zipped1.push_back({s[i] - '0', pascal[i]});
        for (int i = 1; i < s.size(); i++)
            if (i - 1 <= n)
                zipped2.push_back({s[i] - '0', pascal[i - 1]});

        int a = red(zipped1);
        int b = red(zipped2);

        return a == b;
    }
};