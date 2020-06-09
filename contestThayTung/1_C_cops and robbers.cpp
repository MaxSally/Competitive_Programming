//https://vjudge.net/contest/351361#problem/C
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

const int N = 35;
ll inf = 1e9 + 7;

struct Edge{
    int v, rev;
    ll c, f;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pos, level;

    bool dinic_bfs(int s){
        level.assign(n, -1);
        queue<int> q; q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(level[e.v] != -1 || e.c - e.f == 0) continue;
                q.push(e.v);
                level[e.v] = level[u] + 1;
            }
        }
        return (level[t] != -1);
    }

    ll dinic_dfs(int u, ll f){
        if(u == t) return f;
        for(;pos[u] < g[u].size(); ++pos[u]){
            Edge &e = g[u][pos[u]];
            if(level[e.v] - level[u] == 1 && e.c - e.f > 0){
                ll df = dinic_dfs(e.v, min(f, e.c - e.f));
                if(df > 0){
                    e.f += df;
                    g[e.v][e.rev].f -= df;
                    return df;
                }
            }
        }
        return 0;
    }

public:

    MaxFlow(int n){
        this->n = n;
        g.assign(n, vector<Edge>());
    }

    void printGraph(){
        rep(i, 0, n - 1){
            //debug(i); debug(g[i].size());
            cout << i << " ";
            rep(j, 0, (int)g[i].size() - 1){
                cout << g[i][j].v << " " << g[i][j].f << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int a, int b, ll c){
        g[a].pb({b, g[b].size(), c, 0});
        g[b].pb({a, g[a].size() - 1, 0, 0});
    }

    ll findMaxFlow(int s, int t){
        this->t = t;
        ll maxFlow = 0;
        while(dinic_bfs(s)){
            ll df;
            pos.assign(n, 0);
            while(df = dinic_dfs(s, inf)){
                maxFlow += df;
            }
        }
        return maxFlow;
    }
};

char graph[N][N];
int cost[N], actual[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, m, c, s;
    cin >> m >> n >> c; // doi vi tri n, m
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            cin >> graph[i][j];
            if(graph[i][j] == 'B'){
                s = i * m + j;
            }
        }
    }
    rep(i, 0, c - 1){
        cin >> cost[i];
    }
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            if(graph[i][j] == '.' || graph[i][j] == 'B'){
                actual[i][j] = inf;
            }else{
                actual[i][j] = cost[graph[i][j] - 'a'];
            }

        }
    }
    MaxFlow mf(n * m * 2+ 5);
    rep(i, 1, n - 2){
        rep(j, 1, m - 2){
            int node = i * m + j;
            mf.addEdge(node, node + n * m, actual[i][j]);
            rep(k, 0, 3){
                int x = i + dx[k];
                int y = j + dy[k];
                mf.addEdge(node + n * m, x * m + y, inf);
            }
        }
    }
    rep(j, 0, m - 1){
        mf.addEdge(j, j + n * m, actual[0][j]);
        mf.addEdge(j + n * m, n * m * 2, inf);
        mf.addEdge((n - 1) * m + j, (n - 1) * m + j + n * m, actual[n - 1][j]);
        mf.addEdge((n - 1) * m + j + n * m, n * m * 2, inf);
    }
    rep(i, 1, n - 2){
        mf.addEdge(i * m, i * m + n * m, actual[i][0]);
        mf.addEdge(i * m + n * m, n * m * 2, inf);
        mf.addEdge(i * m + m - 1, i * m + m - 1 + n * m, actual[i][m - 1]);
        mf.addEdge(i * m + m - 1 + n * m, n * m * 2, inf);
    }
    ll ans = mf.findMaxFlow(s, n * m * 2);
    //debug(ans);
    //mf.printGraph();
    cout << (ans >= inf? -1LL: ans);
    return 0;
}
