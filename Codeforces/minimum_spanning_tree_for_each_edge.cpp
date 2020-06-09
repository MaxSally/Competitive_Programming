//https://codeforces.com/problemset/problem/609/E
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

struct Edge{
    int u, v, cost, mstValue;
};
int dsu[N], n, m, h[N], b[20][N], d[20][N];
ll mstWeight;
vi graph[N];
vector<Edge> edgeList;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
bool state[N];

int findSet(int u){
    return ((dsu[u] == u)? u: dsu[u] = findSet(dsu[u]));
}

bool joinDSU(int u, int v){
    int a = findSet(u);
    int b = findSet(v);
    //debug(a);
    //debug(b);
    if(a != b){
        dsu[a] = b;
        return true;
    }
    return false;
}

void dfs(int node, vector<bool> &visited){
    visited[node] = 1;
    for(int a: graph[node]){
        Edge e = edgeList[a];
        int v = e.u + e.v - node;
        if(visited[v]) continue;
        h[v] = h[node] + 1;
        b[0][v] = node;
        d[0][v] = e.cost;
        dfs(v, visited);
    }
}

int maxLCA(int u, int v){
    int maxN = 0;
    if(h[u] < h[v]){
        swap(u, v);
    }
    int t = h[u] - h[v];
    rep(i, 0, log2(t)){
        if((t >> i) & 1){
            maxN = max(maxN, d[i][u]);
            u = b[i][u];
        }
    }
    if(u == v) return maxN;
    rrep(i, log2(n), 0){
        if(b[i][u] != b[i][v]){
            maxN = max(max(maxN, d[i][u]), d[i][v]);
            u = b[i][u];
            v = b[i][v];
            //debug(maxN);
        }
    }
    maxN = max(max(maxN, d[0][u]), d[0][v]);
    //debug(u); debug(v);
    return maxN;
}

void prepare(int node){
    vector<bool> visited(n + 1, 0);
    h[node] = 0;
    rep(i, 1, n){
        b[0][i] = -1;
    }
    dfs(node, visited);
    rep(i, 1, (int) log2(n)){
        rep(j, 1, n){
            b[i][j] = b[i - 1][b[i - 1][j]];
            d[i][j] = max(d[i - 1][b[i - 1][j]], d[i - 1][j]);
            //cout << d[i][j] << " ";
        }
        //cout << endl;
    }
}

void minimumSpanningTree(){
    rep(i, 0, n){
        dsu[i] = i;
    }
    mstWeight = 0;
    while(pq.size()){
        int i = pq.top().second;
        Edge e = edgeList[i];
        pq.pop();
        int u = e.u, v = e.v, cost = e.cost;
        if(joinDSU(u, v)){
            mstWeight += 1LL*cost;
            graph[u].pb(i);
            graph[v].pb(i);
            state[i] = 1;
            //debug(u); debug(v);
        }
    }
    //debug(mstWeight);
}



int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    mem(state, 0);
    rep(i, 0, 19){
        mem(b[i], 0);
        mem(d[i], 0);
    }
    rep(i, 0, m - 1){
        int u, v, c; cin >> u >> v >> c;
        edgeList.pb({u, v, c, 0});
        pq.push({c, i});
    }
    minimumSpanningTree();
    prepare(1);
    rep(i, 0, m - 1){
        Edge e = edgeList[i];
        if(state[i]){
            cout << mstWeight << endl;
            continue;
        }
        ll maxN = maxLCA(e.u, e.v);
        //debug(maxN);
        cout << (mstWeight - maxN + e.cost) << endl;
    }
    return 0;
}

