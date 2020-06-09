//https://codeforces.com/problemset/problem/128/C
/*
* Author : MaxSally
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i <= k ; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 3005;
int n, m, k;
ll factorial[N], invF[N];

ll inverseFactorial(ll a){
    int b = mod - 2;
    ll ans = 1LL;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    int l = max(n, m);
    factorial[0] = invF[0] = 1LL;
    rep(i, 1, l){
        factorial[i] = (factorial[i - 1] * i) % mod;
        invF[i] = inverseFactorial(factorial[i]);
    }
    if(n <= (2 * k) || m <= (2 * k)){
        cout << 0 << endl;
        return 0;
    }
    ll cnt1 = 0;
    rep(i, 2 * k - 1, n - 2){
        cnt1 += ((((factorial[i] * invF[2 * k - 1]) % mod) * invF[i - 2*k + 1]) % mod);
        cnt1 %= mod;
    }
    ll cnt2 = 0;
    rep(i, 2 * k - 1, m - 2){
        cnt2 += ((((factorial[i] * invF[2 * k - 1]) % mod) * invF[i - 2*k + 1]) % mod);
        cnt2 %= mod;
    }
    cout << ((cnt1 * cnt2) % mod);
    return 0;
}

