// const int N = 1e5 + 9, LOG = 18;

int root;
vector<vector<int>> v(N), up(N, vector<int>(LOG));
vector<int> depth(N, -1), freq(N), flat; // depth[0] = 0;
vector<pii> pos(N);

struct mo {
    int l, r, p, k;
    bool operator<(const mo &x) {
        if (x.l / root != l / root) return x.l < l;
        return x.r < r;
    }
};

void add(int x) {
    ans += freq[arr[x]] == 0;
    freq[arr[x]]++;
}

void remove(int x) {
    ans -= freq[arr[x]] == 1;
    freq[arr[x]]--;
}

void runMo(vector<mo> &q, vector<int> &ans) {
    // if (q.empty()) return;
    sort(all(q));
    int l = q[0].l, r = q[0].l;
    add(l);
    for (auto [ql, qr, qp, qk] : q) {
        while (r < qr) add(++r);
        while (l > ql) add(--l);
        while (r > qr) remove(r--);
        while (l < ql) remove(l++);
        //ans[qp] = freq[qk];
    }
}