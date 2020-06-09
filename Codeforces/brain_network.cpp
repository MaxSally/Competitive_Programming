//https://codeforces.com/problemset/problem/690/C2
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

const int N = 100005;
int n, m;
vi graph[N];
int dp[3][N];

void dfs(int s, vector<bool> &visited){
    visited[s] = 1;
    dp[1][s] = dp[2][s] = 0;
    for(int v: graph[s]){
        if(visited[v]) continue;
        dfs(v, visited);
        if(dp[1][v] + 1 >= dp[1][s]){
            dp[2][s] = dp[1][s];
            dp[1][s] = dp[1][v] + 1;
        }else if(dp[1][v] + 1 >= dp[2][s]){
            dp[2][s] = dp[1][v] + 1;
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 1, m){
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vector<bool> visited(n + 1, 0);
    dfs(1, visited);
    int maxN = 0;
    rep(i, 1, n){
        maxN = max(maxN, dp[1][i] + dp[2][i]);
    }
    cout << maxN;
    return 0;
}

