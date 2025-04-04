// #define pii pair<int, int>
// const int oo = 0x3f3f3f3f;

struct Edge {
    int from, to, cap, cost;
};

vector<vector<int>> adj, cost, cap;

void bellman(int n, int source, vector<int>& d, vector<int>& p) {
    d.assign(n, oo);
    d[source] = 0;
    vector<bool> inq(n, 0);
    queue<int> q;
    q.push(source);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int v : adj[u]) {
            if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

pii minCostFlow(int n, vector<Edge> &edges, int source, int sink, int k = oo) {
    adj.assign(n, vector<int>());
    cost.assign(n, vector<int>(n, 0));
    cap.assign(n, vector<int>(n, 0));
    for (Edge e: edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        cap[e.from][e.to] = e.cap;
    }

    int flow = 0, c = 0;
    vector<int> d, p;
    while (flow < k) {
        bellman(n, source, d, p);
        if (d[sink] == oo) break;

        int f = k - flow, cur = sink;
        while (cur != source) {
            f = min(f, cap[p[cur]][cur]);
            cur = p[cur];
        }

        flow += f;
        c += f * d[sink];
        cur = sink;
        while (cur != source) {
            cap[p[cur]][cur] -= f;
            cap[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    // if (flow < k) return {-1, -1};
    return {flow, c};
}