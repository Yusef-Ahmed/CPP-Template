// #define pb push_back
// #define ll long long
// const int N = 1e5 + 9;

bool flag[N];
vector<int> primes;

void sieve(){
    for (ll i = 2; i < N; i++) {
        if (flag[i] == 1) continue;
        primes.pb(i);
        for (ll j = i * i; j < N; j += i) flag[j] = 1;
    }
}