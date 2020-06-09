//https://codeforces.com/problemset/problem/191/C
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
int n, h[N], b[20][N], d[N];
vector<int> graph[N];
vii edgeList;

int LCA(int u, int v){
    if(h[u] < h[v]){
        swap(u, v);
    }
    int t = h[u] - h[v];
    rep(i, 0, log2(t)){
        if((t >> i) & 1)
            u = b[i][u];
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

void bfs(int s){
    queue<int> q; q.push(s);
    vector<bool> visited(n, 0);
    visited[s] = 1;
    rep(i, 1, n){
        b[0][i] = -1;
    }
    h[s] = 0;
    while(q.size()){
        int u = q.front(); q.pop();
        for(int a: graph[u]){
            if(visited[a]) continue;
            visited[a] = 1;
            q.push(a);
            b[0][a] = u;
            h[a] = h[u] + 1;
        }
    }
    rep(i, 1, (int)log2(n)){
        rep(j, 1, n){
            b[i][j] = b[i - 1][b[i - 1][j]];
        }
    }
}

int dp(int s, vector<bool> &visited){
    visited[s] = 1;
    if((int)graph[s].size() == 1 && h[s] != 0){
        return d[s];
    }
    int totalFool = 0;
    for(int a: graph[s]){
        if(visited[a]) continue;
        totalFool += dp(a, visited);
    }
    d[s] += totalFool;
    return d[s];
}

int main(){
    io
    freopen("input.txt","r",stdin);
    mem(d, 0);
    mem(h, 0);
    rep(i, 0, 19){
        mem(b[i], 0);
    }
    cin >> n;
    rep(i, 1, n - 1){
        int u, v; cin >> u >> v;
        edgeList.pb({u, v});
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int k; cin >> k;
    bfs(1);
    while(k--){
        int a, b; cin >> a >> b;
        int ancestor = LCA(a, b);
        d[a]++; d[b]++;
        d[ancestor] -= 2;
    }
    //cout << "d ";
    //debuga1(d, 1, n);
    vector<bool> visited(n + 1, 0);
    int ans = dp(1, visited);
    //cout << "d ";
    //debuga1(d, 1, n);
    for(pair<int,int> a: edgeList){
        if(h[a.first] < h[a.second]){
            swap(a.first, a.second);
        }
        cout << d[a.first] << " ";
    }
    return 0;
}
