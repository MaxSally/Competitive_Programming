//https://www.spoj.com/problems/MATCHING/
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
#define Flag cout << "here" << endl
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

const int N = 50005;
const int M = 150005;
int n, m, p;

struct Edge{
    int v, rev, c, f;
};

class MaxFlow{
private:
    int n, m, p, t;
    vi level, pos;
    vector<vector<Edge> > g;

    bool dinic_bfs(int s){
        level.assign(n, -1);
        queue<int> q; q.push(s);
        level[s] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(level[e.v] != -1 || e.c - e.f == 0) continue;
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
        return level[t] > 0;
    }

    int dinic_dfs(int u, int f){
        if(u == t)
            return f;
        for(;pos[u] < g[u].size(); ++pos[u]){
            Edge &e = g[u][pos[u]];
            if(level[e.v] - level[u] == 1 && e.c - e.f > 0){
                int df = dinic_dfs(e.v, min(f, e.c - e.f));
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
    void addEdge(int a, int b){
        g[a].pb({b, g[b].size(), 1, 0});
        g[b].pb({a, g[a].size() - 1, 0, 0});
    }

    int findMaxFlow(int s, int t){
        this->t = t;
        int maxFlow = 0;
        while(dinic_bfs(s)){
            pos.assign(n, 0);
            int df;
            while(df = dinic_dfs(s, inf)){
                maxFlow += df;
            }
        }
        return maxFlow;
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> m >> p;
    MaxFlow MF(n + m + 2);
    rep(i, 1, p){
        int x, y; cin >> x >> y;
        MF.addEdge(x, y + n);
    }
    rep(i, 1, n){
        MF.addEdge(0, i);
    }
    rep(i, n + 1, n + m){
        MF.addEdge(i, n + m + 1);
    }
    cout << MF.findMaxFlow(0, n + m + 1);
    return 0;
}
