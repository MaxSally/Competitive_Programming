//https://codeforces.com/problemset/problem/313/D
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
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl;
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

const int N = 305;
const ll inf = (1e15) + 9;
ll dp[N][N], cost[N][N];
int n, m, k;

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    rep(i, 0, n){
        rep(j, 0, n){
            dp[i][j] = cost[i][j] = inf;
        }
    }
    rep(i, 1, m){
        int u, v, c; cin >> u >> v >> c;
        u--;
        cost[u][v] = min(cost[u][v], 1LL*c);
    }
    rep(j, 0, n){
        rep(i, 1,  n){
            cost[i][j] = min(cost[i][j], cost[i - 1][j]);
        }
    }
    rep(i, 0, n){
        dp[i][0] = 0;
        rep(len, 0, i){
            if(dp[i][len] == inf) continue;
            dp[i + 1][len] = min(dp[i + 1][len], dp[i][len]);
            rep(nxt, i + 1, n){
                dp[nxt][len + (nxt - i)] = min(dp[nxt][len + (nxt - i)], dp[i][len] + cost[i][nxt]);
            }
        }
    }
    ll ans = inf;
    rep(i, k, n){
        ans = min(ans, dp[n][i]);
    }
    if(ans >= inf)  ans = -1;
    cout << ans;

    return 0;
}
