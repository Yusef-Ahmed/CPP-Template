vector<int> computePrefix(string pat) {
    int m = pat.size();
    vector<int> longestPrefix(m);
    for (int i = 1, k = 0; i < m; i++) {
        while (k > 0 && pat[k] != pat[i]) {
            k = longestPrefix[k - 1];
        }
        if (pat[i] == pat[k]) {
            longestPrefix[i] = ++k;
        } else {
            longestPrefix[i] = k;
        }
    }
    return longestPrefix;
}

void kmp(string str, string pat) {
    int n = str.size(), m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    for (int i = 0, k = 0; i < n; i++) {
        while (k > 0 && pat[k] != str[i]) {
            k = longestPrefix[k - 1];
        }
        if (str[i] == pat[k]) {
            k++;
        }
        if (k == m) {
            cout << i - m + 1 << endl;
            k = longestPrefix[k - 1];
        }
    }
}

// void solve() {
//     vector<int> fail = computePrefix(s), ans(n + 1, 1);
    
//     for (int i = 0; i < n; i++) {
//         ans[fail[i]]++;
//     }
    
//     for (int i = n - 1; i > 0; i--) {
//         ans[fail[i - 1]] += ans[i] - 1;
//     }
    
//     for (int i = 1; i <= n; i++) cout << ans[i] << " ";
// }