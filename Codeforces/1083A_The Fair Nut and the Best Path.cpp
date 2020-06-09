//https://codeforces.com/problemset/problem/1083/A
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
#define inf (long long) (1e18 + 7)
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

const int N = 300005;
int n, w[N], level[N];
ll down[2][N];
vii graph[N];

void bfs(int s, int parent){
    foreach(u, graph[s]){
        int v = u.ff;
        int c = u.ss;
        if(v == parent) continue;
        level[v] = level[s] + 1;
        bfs(v, s);
        if(down[0][v] - c >= down[0][s]){
            down[1][s] = down[0][s];
            down[0][s] = down[0][v] - c;
        }else if(down[0][v] - c >= down[1][s]){
            down[1][s] = down[0][v] - c;
        }
    }
    down[0][s] += w[s];
    down[1][s] += w[s];
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    mem(down[0], 0);
    mem(down[1], 0);
    rep(i, 1, n){
        cin >> w[i];
    }
    rep(i, 1, n - 1){
        int u, v, c; cin >> u >> v >> c;
        graph[u].pb(mp(v, c));
        graph[v].pb(mp(u, c));
    }
    bfs(1, -1);
    ll maxN = 0;
    rep(i, 1, n){
        maxN = max(maxN, down[0][i] + down[1][i] - w[i]);
    }
    cout << maxN;
    return 0;
}
