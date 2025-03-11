vector<vector<int>> v, bridgeTree;
vector<int> low, dfn, comp;
set<pii> bridges; // #define pii pair<int,int>
vector<bool> vis;
int ndfn;

void tarjan_bridge(int node, int par = -1) {
    low[node] = dfn[node] = ndfn++;

    for (int ch: v[node]) {
        if (dfn[ch] == -1) {
            tarjan_bridge(ch, node);
            low[node] = min(low[node], low[ch]);
            if (low[ch] > dfn[node]) {
                bridges.insert({min(node, ch), max(node, ch)});
            }
        } else if (ch != par) {
            low[node] = min(low[node], dfn[ch]);
        }
    }
}

void scc(int n) {
    v.clear();
    v = vector<vector<int>> (n + 1);
    vis = vector<bool>(n + 1);
    low.clear(), low.resize(n + 1);
    dfn.clear(), dfn.resize(n + 1, -1);
    bridges.clear();
    comp.resize(n + 1);
    ndfn = res = 0;
}
// scc(n); "after n"
// for (int i = 0; i < n; i++) if (dfn[i] == -1) tarjan_bridge(i); // (zero base)

void dfs(int i, int &cnt) {
    vis[i] = 1;
    comp[i] = cnt;
    for (int x : v[i]) if (!vis[x] && !bridges.count({min(i, x), max(i, x)})) {
        dfs(x, cnt);
    }
}

void bridge_tree(int n) {
    tarjan_bridge(0);
    int cnt = -1;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        cnt++;
        dfs(i, cnt);
    }
    bridgeTree = vector<vector<int>>(cnt + 1);
    for (auto [x, y] : bridges) {
        bridgeTree[comp[x]].push_back(comp[y]);
        bridgeTree[comp[y]].push_back(comp[x]);
    }
}
