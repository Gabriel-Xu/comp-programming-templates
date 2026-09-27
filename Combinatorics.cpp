typedef long long ll;

const ll mod=1e9+7;
const int MAXN = 2e5;
ll fac[MAXN + 1];
ll fac_inv[MAXN + 1];

ll inverse(ll a) {
  	return a <= 1 ? a : mod - (mod/a) * inverse(mod % a) % mod;
}

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}
void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % mod; }
}
void inverses() {
	fac_inv[MAXN] = exp(fac[MAXN], mod - 2, mod);
	for (int i = MAXN; i >= 1; i--) { fac_inv[i - 1] = fac_inv[i] * i % mod; }
}
ll choose(ll n, ll r) {
	if (r == 0) return 1;
	return fac[n] * fac_inv[r] % mod * fac_inv[n - r] % mod;
}
// call factorial, then inverses at start
