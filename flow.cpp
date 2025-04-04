// #define pii pair<int, int>
// const int oo = 0x3f3f3f3f;

int n;
vector<vector<int>> cap;
vector<int> par;

int bfs(int source, int sink) {
    fill(all(par), -1);
    queue<pii> q;
    q.push({source, oo});

    while (!q.empty()) {
        auto [cur, flow] = q.front();
        q.pop();
        for (int next = source; next <= sink; next++) {
            if (par[next] == -1 && cap[cur][next]) {
                par[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == sink) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxFlow(int source, int sink) {
    int flow = 0, new_flow = bfs(source, sink);
    while (new_flow) {
        flow += new_flow;
        int cur = sink;
        while (cur != source) {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(source, sink);
    }
    return flow;
}

void pre(int sz = n) {
    par.resize(sz + 1);
    cap = vector<vector<int>>(sz + 1, vector<int>(sz + 1));
}