//https://codeforces.com/gym/254631/problem/C
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
#define foreach(i, a) for(auto i: a)
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
#define ss second
#define ff first
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

const int N = 255;
ll C[N][N], kPower[N * N], k_1Power[N * N], fact[N], invF[N];
int n, k;

ll multiply(ll a, int b){
    ll ans = 1LL;
    while(b){
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
    cin >> n >> k;
    if(k == 1){
        cout << 1;
        return 0;
    }
    kPower[0] = k_1Power[0] = fact[0] = 1;
    invF[0] = multiply(fact[0], mod - 2);
    rep(i, 1, n){
        fact[i] = (fact[i - 1] * i) % mod;
        invF[i] = multiply(fact[i], mod - 2);
    }
    rep(i, 0, n){
        rep(j, 0, i){
            C[i][j] = (((fact[i] * invF[j]) % mod) * invF[i - j]) % mod;
        }
    }
    rep(i, 1, n * n){
        kPower[i] = (kPower[i - 1] * k) % mod;
        k_1Power[i] = (k_1Power[i - 1] * (k - 1)) % mod;
    }
    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            ans = (ans + ((((C[n][i] * C[n][j]) % mod) * ((i + j) & 1? -1: 1) * kPower[(n - i) * (n - j)]) % mod) * k_1Power[n * n - (n - i) * (n - j)] + mod) % mod;
        }
    }
    cout << ans;
    return 0;
}

