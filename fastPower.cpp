// #define ll long long
// const int mod = 1e9 + 7;

ll fp(ll base, ll power) {
    ll result = 1;
    while (power > 0) {
        if (power & 1) result *= base;
        base *= base;
        power /= 2;
    }
    return result;
}

ll fp(ll base, ll power) { // with mod
    if (power == 0) return 1;
    ll ans = fp(1LL * base * base % mod, power / 2);
    if (power % 2) return 1LL * ans * base % mod;
    return ans;
}