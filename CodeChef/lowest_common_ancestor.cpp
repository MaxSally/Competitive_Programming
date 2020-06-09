//https://www.codechef.com/problems/TALCA
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

const int N = 200005;
int h[N], b[20][N], n;
vi graph[N];

int LCA(int u, int v){
    if(h[u] < h[v]){
        swap(u, v);
    }
    int t = h[u] - h[v];
    rep(i, 0, log2(t)){
        if((t >> i) & 1){
            u = b[i][u];
        }
    }
    if(u == v) return u;
    rrep(i, log2(n), 0){
        if(b[i][u] != b[i][v]){
            u = b[i][u];
            v = b[i][v];
        }
    }
    return b[0][u];
}

void dfs(int s, vector<bool> &visited){
    visited[s] = 1;
    for(int a: graph[s]){
        if(visited[a]) continue;
        h[a] = h[s] + 1;
        b[0][a] = s;
        dfs(a, visited);
    }
}

void prepare(int node){
    vector<bool> visited(n + 1, 0);
    h[node] = 0;
    rep(i, 1, n){
        b[0][i] = -1;
    }
    dfs(node, visited);
    rep(i, 1, log2(n)){
        rep(j, 1, n){
            b[i][j] = b[i - 1][b[i - 1][j]];
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 1, n - 1){
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int q; cin >> q;
    prepare(1);
    while(q--){
        int u, v, r;
        cin >> r >> u >> v;
        int a = LCA(r, u), b = LCA(u, v), c = LCA(r, v);
        int maxN = max(max(h[a], h[b]), h[c]);
        if(maxN == h[a]) cout << a;
        else if(maxN == h[b]) cout << b;
        else cout << c;
        cout << endl;
    }
    return 0;
}
