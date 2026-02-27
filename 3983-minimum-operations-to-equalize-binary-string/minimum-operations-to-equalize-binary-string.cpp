class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int z = 0;
        for (char c : s) {
            if (c == '0')
                z++;
        }
        if (z == 0)
            return 0;
        vector<int> dist(n + 1, -1);
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            if (i != z) {
                unvisited[i % 2].insert(i);
            }
        }

        queue<int> q;
        q.push(z);
        dist[z] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int max_zeros_flipped = min(k, curr);
            int min_zeros_flipped = max(0, k - (n - curr));
            int L = curr + k - 2 * max_zeros_flipped;
            int R = curr + k - 2 * min_zeros_flipped;
            int p = (curr + k) % 2; 
            auto it = unvisited[p].lower_bound(L);
            vector<int> to_erase;
            while (it != unvisited[p].end() && *it <= R) {
                int next_z = *it;

                dist[next_z] = dist[curr] + 1;
                if (next_z == 0)
                    return dist[0];

                q.push(next_z);
                to_erase.push_back(next_z);
                ++it;
            }
            for (int val : to_erase) {
                unvisited[p].erase(val);
            }
        }

        return -1;
    }
};