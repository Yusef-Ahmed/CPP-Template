// const int LOG = 18;

int ancestor(int x, int k) {
    for (int i = LOG - 1; i >= 0; i--) {
        if ((1 << i) & k) {
            x = up[x][i];
        }
    }
    return x;
}