class Solution {
public:
    int N;
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            int px = parent[x];
            if (px != parent[px])
                parent[x] = find(px);
            return parent[x];
        }
        bool isCycle(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py)
                return true;
            return false;
        }
        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);

            if (rank[px] > rank[py])
                parent[py] = px;
            else if (rank[px] < rank[py])
                parent[px] = py;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
        int components() {
            unordered_set<int> s;
            for (int i = 0; i < parent.size(); i++) {
                s.insert(find(i));
            }
            return s.size();
        }
    };
    bool check(int mx, vector<vector<int>>& edges, int k) {
        DSU tree = DSU(N);
        for (auto& v : edges) {
            if (v[3] == 1) {
                if (v[2] < mx || tree.isCycle(v[0], v[1]))
                    return false;
                tree.unite(v[0], v[1]);
            }
        }
        
        for (auto& v : edges) {
            if (v[3] == 0) {
                if (!tree.isCycle(v[0], v[1])) {
                    int st = v[2];
                    if (k > 0 && st < mx)
                        st *= 2;
                    if (st >= mx) {
                        k+=(st!=v[2])?-1:0;
                        tree.unite(v[0], v[1]);
                    }
                }
            }
        }
        int tc = tree.components();
        return tc == 1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        N = n;
        sort(edges.begin(), edges.end(),
             [&](auto& a, auto& b) { return a[2] > b[2]; });
        int l = 1, h = 200000, res = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(mid, edges, k)) {
                res = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        return res;
    }
};