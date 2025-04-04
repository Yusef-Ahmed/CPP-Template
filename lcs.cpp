string LCS(string &x, string &y) {
    int m = x.size(), n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // return dp[m][n];

    string lcs = "";
    while (m && n) {
        if (x[m - 1] == y[n - 1]) {
            lcs += x[m - 1];
            m--, n--;
        } else if (dp[m - 1][n] > dp[m][n - 1]) {
            m--;
        } else {
            n--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}