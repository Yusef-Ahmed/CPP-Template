// const int N = 1e5 + 9, LOG = 18;
// #define F first
// #define S second
// #define pb push_back
// #define pii pair<int, int>

vector<vector<int>> v(N), up(N, vector<int>(LOG));
vector<int> depth(N, -1), flat; // depth[head] = 0;
vector<pii> pos(N);

void dfs(int i) {
    pos[i].F = flat.size();
    flat.pb(i);
    for (int x: v[i]) {
        if (~depth[x]) continue;
        depth[x] = depth[i] + 1;
        up[x][0] = i;
        for (int k = 1; k < LOG; k++) {
            up[x][k] = up[up[x][k - 1]][k - 1];
        }
        dfs(x);
    }
    pos[i].S = flat.size() - 1;
}

void binaryLifting(int i) {depth[i] = 0, dfs(i);}