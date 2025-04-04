vector<vector<int>> v, comps;
vector<int> low, dfn, comp;
vector<bool> inStack;
stack<int> stk;
int ndfn;

void tarjan(int node) {
    low[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);

    for (int ch: v[node]) {
        if (dfn[ch] == -1) {
            tarjan(ch);
            low[node] = min(low[node], low[ch]);
        } else if (inStack[ch]) {
            low[node] = min(low[node], dfn[ch]);
        }
    }

    if (low[node] == dfn[node]) { // source
        comps.push_back(vector<int>());
        int x = -1;
        while (x != node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
            comp[x] = comps.size() - 1;
        }
    }
}

void scc(int n) {
    v.clear();
    v = vector<vector<int>> (n + 1);
    inStack.clear(), inStack.resize(n + 1);
    low.clear(), low.resize(n + 1);
    dfn.clear(),     dfn.resize(n + 1, -1);
    comp.clear(),    comp.resize(n + 1);
    comps.clear();
    ndfn = 0;
}
// scc(n); "after n"
// for (int i = 0; i < n; i++) if (dfn[i] == -1) tarjan(i); // (zero base)

// --------------------------------------------------------------------

vector<vector<int>> v, comps, dagList;
vector<int> low, dfn, comp, inDeg, outDeg;
vector<bool> inStack;
stack<int> stk;
int ndfn;

void computeCompGraph() {
    int csz = comps.size(), cntSrc = csz, cntSnk = csz;

    outDeg.clear(), outDeg.resize(csz);
    inDeg.clear(), inDeg.resize(comps.size());
    dagList.clear(), dagList.resize(csz);

    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[i].size(); j++) {
            int k = v[i][j];
            if (comp[k] != comp[i]) {
                dagList[comp[i]].push_back(comp[k]);
                if (!(inDeg[comp[k]]++)) cntSrc--;
                if (!(outDeg[comp[i]]++)) cntSnk--;
            }
        }
//    Min edges to convert DAG to one cycle
//    if (comps.size() == 1)
//        cout << "0\n";
//    else {
//        cout << max(cntSrc, cntSnk) << "\n";
//    }
}