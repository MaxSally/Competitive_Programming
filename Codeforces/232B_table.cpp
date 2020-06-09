//https://codeforces.com/problemset/problem/232/B
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

const int N = 105;
ll dp[N][10005], factorial[N], invF[N], m;
int n, k;

void printDP(){
    rep(i, 0, n - 1){
        rep(j, 0, k){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

ll power(ll a, ll b){
    ll ans = 1;
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
    rep(i, 0, n - 1){
        mem(dp[i], 0);
    }
    mem(factorial, 0);
    mem(invF, 0);
    factorial[0] = invF[0] = 1;
    rep(i, 1, n){
        factorial[i] = (factorial[i - 1] * i) % mod;
        invF[i] = power(factorial[i], mod - 2);
    }
    //debuga1(factorial, 0, 12);
    rep(i, 1, n){
        ll combi = (((factorial[n] * invF[i]) % mod) * invF[n - i]) % mod;
        ll powe = m/n;
        if(m % n) powe++;
        dp[0][i] = power(combi, powe);
    }
    dp[0][0] = 1;
    rep(i, 1, n - 1){
        rep(l, 0, n){
            ll combi = (((factorial[n] * invF[l]) % mod) * invF[n - l]) % mod;
            ll powe = m/n;
            if(i  < (m % n)) powe++;
            ll temp = power(combi, powe);
            //debug(i); debug(l); debug(temp);
            rep(j, l, k){
                //debug(i); debug(j); debug(combi); debug(powe);
                dp[i][j] += ((dp[i - 1][j - l]  * temp) % mod);
                dp[i][j] %= mod;
                //debug(dp[i][j]);
            }
            //printDP();
        }
    }
    //printDP();
    cout << dp[n - 1][k];
    return 0;
}

