#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second

ll fact[200001], ans[200001], ans1[200001];
ll ans2[200001];
pll arr[2100];
ll inv(ll a)
{
	ll ans = 1ll, b = MOD-2;
	while (b) {
		if (b&1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}

bool before(pll a, pll b)
{
	if (a.fi <= b.fi && a.sc <= b.sc) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    freopen("input.txt","r",stdin);
	ll n, m, k, i, j, x, y, a, b, c;

	fact[0] = 1ll;
	for (i = 1; i <= 200000; ++i) {
		fact[i] = (i * fact[i-1]) % MOD;
	}
	cin >> n >> m >> k;
	for (i = 1; i <= k; ++i) cin >> arr[i].fi >> arr[i].sc;
	arr[i].fi = n;
	arr[i].sc = m;
	k++;

	sort(arr+1, arr+1+k);
	for (i = 1; i <= k; ++i) {
		x = ((fact[arr[i].fi + arr[i].sc - 2] * inv(fact[arr[i].fi - 1]) % MOD) * inv(fact[arr[i].sc - 1])) % MOD;
		//cout << "x = " << x << " y = ";
		for (j = 1; j <= k; ++j) {
			if (before(arr[j], arr[i])) {
				a = arr[i].fi - arr[j].fi;
				b = arr[i].sc - arr[j].sc;
				y = ((fact[a+b] * inv(fact[a]) % MOD) * inv(fact[b])) % MOD;
				x = (x - (ans[j] * y)%MOD + MOD) % MOD;
				cout << x << endl;
				//cout << i << " " << j << endl;
			}
		}
		//cout << " x = " << x << endl;
		ans[i] = x;
	}

	cout << x << endl;

	return 0;
}
