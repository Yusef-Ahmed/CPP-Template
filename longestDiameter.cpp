int res;

int diameter(int i, int par = -1) {
    vector<int> maxi(3);
    for (int x : bridgeTree[i]) if (x != par) {
        maxi[0] = diameter(x, i) + 1;
        sort(all(maxi));
    }
    res = max(res, maxi[1] + maxi[2]);
    return maxi[2];
}