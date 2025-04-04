struct Kuhn {
    int n, m;
    vector<int> mt;
    vector<bool> vis;
    vector<vector<int>> g;

    Kuhn(vector<vector<int>> &g, int &n, int &m) : g(g), n(n), m(m) {
        vis.resize(n);
        mt.assign(m, -1);
    }

    bool match(int u) {
        if (vis[u]) return 0;
        vis[u] = 1;
        for (auto v: g[u]) {
            if (mt[v] == -1 || match(mt[v])) {
                mt[v] = u;
                return 1;
            }
        }
        return 0;
    }

    int maxMatch() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            fill(all(vis), 0);
            ans += match(i);
        }
        return ans;
    }
};