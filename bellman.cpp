// #define pii pair<int, int>
// #define ll long long
// #define F first
// #define S second
// const int oo = 0x3f3f3f3f;

int n, m;
vector<pair<int, pii>> adj;
ll mn = oo; 
ll dis[N];

int bellman() {
    for (int i = 0; i < n; i++) {
        for (auto j: adj){
            int from = j.F, to = j.S.F, w = j.S.S;
            if (dis[to] > dis[from] + w) {
                dis[to] = dis[from] + w;
                mn = min(mn, dis[to]);
                if (i == n - 1) return 1;
            }
        }
    }
    return 0;
}