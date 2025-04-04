vector<vector<int>> v;
vector<int> low, dfn;
set<pii> bridges;
int ndfn;

void tarjanBridge(int node, int par = -1) {
    low[node] = dfn[node] = ndfn++;

    for (int ch: v[node]) {
        if (dfn[ch] == -1) {
            tarjanBridge(ch, node);
            low[node] = min(low[node], low[ch]);
            if (low[ch] > dfn[node]) {
                bridges.insert({node, ch});
            }
        } else if (ch != par) {
            low[node] = min(low[node], dfn[ch]);
        }
    }
}

void scc(int n) {
    v.clear();
    v = vector<vector<int>> (n + 1);
    low.clear(), low.resize(n + 1);
    dfn.clear(), dfn.resize(n + 1, -1);
    bridges.clear();
    ndfn = 0;
}
// scc(n); "after n"
// for (int i = 0; i < n; i++) if (dfn[i] == -1) tarjan_bridge(i); // (zero base)
