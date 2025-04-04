vector<vector<int>> v;
vector<int> low, dfn;
set<int> articulation;
int ndfn;

void tarjanArticulation(int node, int par = -1) {
    low[node] = dfn[node] = ndfn++;
    int anc = 0;
    for (int ch: v[node]) {
        if (dfn[ch] == -1) {
            tarjanArticulation(ch, node);
            low[node] = min(low[node], low[ch]);
            if (low[ch] >= dfn[node] && ~par) {
                articulation.insert(node);
            }
            anc++;
        } else if (ch != par) {
            low[node] = min(low[node], dfn[ch]);
        }
    }
    if (par == -1 && anc > 1) {
        articulation.insert(node);
    }
}

void scc(int n) {
    v.clear();
    v = vector<vector<int>> (n + 1);
    low.clear(), low.resize(n + 1);
    dfn.clear(), dfn.resize(n + 1, -1);
    articulation.clear();
    ndfn = 0;
}

// scc(n); "after n"
// for (int i = 0; i < n; i++) if (dfn[i] == -1) tarjan_articulation(i); // (zero base)