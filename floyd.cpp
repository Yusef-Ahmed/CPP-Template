// const int oo = 0x3f3f3f3f;

int d[n + 1][n + 1];

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        d[i][j] = (i == j ? 0 : oo);
    }
}

for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}