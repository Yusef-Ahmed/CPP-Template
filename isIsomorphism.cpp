class Tree {
public:
    vector<vector<int>> adj;
    vector<int> centroid, sub, id;
    vector<ll> powr;

    void dfs(int curNode, int prevNode) {
        sub[curNode] = 1;
        bool is_centroid = true;
        vector<pair<int, int>> nodes;
        for (int v: adj[curNode]) {
            if (v != prevNode) {
                dfs(v, curNode);
                sub[curNode] += sub[v];
                if (sub[v] > (int) adj.size() / 2) {
                    is_centroid = false;
                }
                nodes.emplace_back(id[v], v);
            }
        }
        sort(nodes.begin(), nodes.end());
        id[curNode] = 1;
        for (auto& p: nodes) {
            id[curNode] = ((powr[sub[p.second] + 1] * id[curNode]) % mod + id[p.second]) % mod;
        }
        id[curNode] *= 2;
        id[curNode] %= mod;
        if ((int) adj.size() - sub[curNode] > (int) adj.size() / 2) {
            is_centroid = false;
        }
        if (is_centroid) {
            centroid.push_back(curNode);
        }
    }

    vector<int> Centroid() {
        dfs(0, -1);
        return centroid;
    }

    bool isIsomorphic(int root1, Tree t2, int root2) {
        dfs(root1, root1);
        t2.dfs(root2, root2);
        sort(sub.begin(), sub.end());
        sort(t2.sub.begin(), t2.sub.end());
        return (id[root1] == t2.id[root2]);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v), adj[v].push_back(u);
    }

    Tree(int n) {
        adj.resize(n);
        sub.resize(n);
        id.resize(n);
        powr.resize(n + 1);
        powr[0] = 1;
        for (int i = 1; i <= n; i++) {
            powr[i] = powr[i - 1] << 1;
            powr[i] %= mod;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    Tree v1(n), v2(n);
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y; x--, y--;
        v1.add_edge(x, y);
    }
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y; x--, y--;
        v2.add_edge(x, y);
    }
    vector<int> c1 = v1.Centroid();
    vector<int> c2 = v2.Centroid();
    bool done = false;
    for (int i: c1) {
        for (int j: c2) {
            if (v1.isIsomorphic(i, v2, j)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}