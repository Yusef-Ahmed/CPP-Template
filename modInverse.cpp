// #define ll long long

ll modPow(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInv(ll x, ll m) {
    return modPow(x, m - 2, m);
}

ll division(ll a, ll b) {
    ll b_inv = modInv(b, MOD);
    return (1LL * (a % MOD) * b_inv) % MOD;
}

ll mul(ll a, ll b) {
    return (1ll * (a % MOD) * (b % MOD)) % MOD;
}