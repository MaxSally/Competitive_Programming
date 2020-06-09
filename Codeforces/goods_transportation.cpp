//https://codeforces.com/problemset/problem/724/E
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
#define inf (long long) (1e18 + 7)
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

const int N = 10005;

struct Edge{
    int v, rev;
    ll c, f;
};

class MaxFlow{
private:
    int n, t;
    vi level, pos;
    vector<vector<Edge> > g;

    bool dinic_bfs(int s){
        level.assign(n, -1);
        queue<int> q; q.push(s);
        level[s] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            //debug(u);
            for(Edge e: g[u]){
                if(level[e.v] == -1 && e.c - e.f > 0){
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] > 0;
    }

    ll dinic_dfs(int u, ll f){
        if(u == t)
            return f;
        for(; pos[u] != g[u].size(); ++pos[u]){
            Edge &e = g[u][pos[u]];
            if(level[e.v] - level[u] == 1 && e.c - e.f > 0LL){
                ll df = dinic_dfs(e.v, min(f, e.c - e.f));
                if(df == 0) continue;
                e.f += df;
                g[e.v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

public:
    MaxFlow(int n){
        this->n = n;
        g.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int c){
        g[u].pb({v, g[v].size(), c, 0});
        g[v].pb({u, g[u].size() - 1, 0, 0});
    }

    ll getFlow(int s, int t){
        this->t = t;
        ll maxFlow = 0;
        while(dinic_bfs(s)){
            pos.assign(n, 0);
            ll df;
            while(df = dinic_dfs(s, 1LL*inf)){
                maxFlow += df;
            }
        }
        return maxFlow;
    }

    void printGraph(){
        rep(i, 0, n - 1){
            //debug(i); debug(g[i].size());
            cout << i << endl;
            rep(j, 0, (int)g[i].size() - 1){
                Edge e = g[i][j];
                cout << e.v << " " << e.c << " " << e.f << endl;
            }
            cout << endl;
        }
    }
};

vector<ll> pre, cur; //dp[u][i]: u = nth vertices assessing; i: # of vertices in belongs to s
vector<int> p, s;
int n, c;

void dp(){
    pre.assign(n + 1, 1LL*inf);
    cur.assign(n + 1, 0LL);
    pre[0] = 0LL;
    rep(u, 1, n){
        cur[0] = pre[0] + p[u];
        rep(i, 1, u){
            cur[i] = min(pre[i - 1] + 1LL*s[u], pre[i] + 1LL*p[u] + 1LL*i * c);
        }
        rep(i, 0, u){
            pre[i] = cur[i];
        }
        //debuga1(pre, 0, u);
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> c;
    p.assign(n + 1, 0);
    s.assign(n + 1, 0);
    rep(i, 1, n){
        cin >> p[i];
    }
    rep(i, 1, n){
        cin >> s[i];
    }
    dp();
    //debuga1(pre, 0, n);
    ll ans = 1LL*inf;
    rep(i, 0, n){
        ans = min(ans, pre[i]);
    }
    cout << ans << endl;
    return 0;
}
