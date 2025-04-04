vector<int> zAlgo(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    for (int x: z) cout << x << " ";
    cout << endl;
    return z;
}

void solve () {
    vector<int> fail = zAlgo(s), ans(n + 1, 1);
    for (int i = 0; i < n; i++) {
        ans[fail[i]]++;
    }
    for (int i = n - 1; i > 0; i--) {
        ans[i - 1] += ans[i] - 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}