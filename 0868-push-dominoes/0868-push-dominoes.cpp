class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        vector<int> indexes;
        vector<char> symbols;

        indexes.push_back(-1);
        symbols.push_back('L');

        for (int i = 0; i < N; ++i) {
            if (dominoes[i] != '.') {
                indexes.push_back(i);
                symbols.push_back(dominoes[i]);
            }
        }

        indexes.push_back(N);
        symbols.push_back('R');

        vector<char> ans(dominoes.begin(), dominoes.end());

        for (size_t index = 0; index < indexes.size() - 1; ++index) {
            int i = indexes[index], j = indexes[index + 1];
            char x = symbols[index], y = symbols[index + 1];

            if (x == y) {
                for (int k = i + 1; k < j; ++k)
                    ans[k] = x;
            } else if (x == 'R' && y == 'L') {
                for (int k = i + 1; k < j; ++k)
                    ans[k] = (k - i == j - k) ? '.' : (k - i < j - k ? 'R' : 'L');
            }
        }

        return string(ans.begin(), ans.end());
    }
};