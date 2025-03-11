int ancestor(int x, int k) {
    for (int i = LOG - 1; i >= 0; i--) { // LOG = 18
        if ((1 << i) & k) {
            x = up[x][i];
        }
    }
    return x;
}