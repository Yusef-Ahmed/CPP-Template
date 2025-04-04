// const int N = 1e5 + 9, LOG = 18;
// #define F first
// #define S second
// #define pb push_back
// #define pii pair<int, int>

vector<vector<int>> v(N), up(N, vector<int>(LOG));
vector<int> depth(N, -1); // depth[head] = 0;

void dfs(int i) {
    for (int x : v[i]) {
        if (~depth[x]) continue;
        depth[x] = depth[i] + 1;
        up[x][0] = i;
        for (int k = 1; k < LOG; k++) {
            up[x][k] = up[up[x][k - 1]][k - 1];
        }
        dfs(x);
    }
}
void binaryLifting(int i) {depth[i] = 0, dfs(i);}

int lca(int x, int y) {
    if (depth[y] < depth[x]) swap(x, y); // x above y
    int k = depth[y] - depth[x];

    for (int i = LOG - 1; i >= 0; i--) {
        if ((1 << i) & k) {
            y = up[y][i];
        }
    }
    if (x == y) return x;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}

int dis(int x, int y) {
    int rt = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[rt];
}