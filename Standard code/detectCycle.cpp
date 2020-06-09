//https://codeforces.com/problemset/problem/720/B
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

const int N = 10005;
vvi cycle, graph;

struct triad{
    int x, y, c, cycInd; // x to y with color c whether used or not
};

vector<triad> edgeList;

struct Edge{
    int v, rev, c, f;
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

    int dinic_dfs(int u, int f){
        if(u == t) return f;
        for(;pos[u] < g[u].size(); ++pos[u]){
            Edge &e = g[u][pos[u]];
            if(level[e.v] - level[u] == 1 && e.c - e.f > 0){
                int df = dinic_dfs(e.v, min(f, e.c - e.f));
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
                cout << g[i][j].v << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int a, int b, int c){
        g[a].pb({b, g[b].size(), c, 0});
        g[b].pb({a, g[a].size() - 1, 0, 0});
    }

    int findMaxFlow(int s, int t){
        this->t = t;
        int maxFlow = 0;
        while(dinic_bfs(s)){
            int df;
            pos.assign(n, 0);
            while(df = dinic_dfs(s, inf)){
                maxFlow += df;
            }
        }
        return maxFlow;
    }
};

vector<int> parent, edge, d; //d is like level vector

void detectCycle(int u){
    for(int node : graph[u]){
        int next = edgeList[node].y + edgeList[node].x - u;
        if(next == parent[u]) continue;
        //debug(u);
        //debug(next);
        if(d[next] == -1){
            d[next] = d[u] + 1;
            edge[next] = node;
            parent[next] = u;
            detectCycle(next);
        }else if(d[next] < d[u]){
            vector<int> newCyc;
            newCyc.pb(node);
            edgeList[node].cycInd = cycle.size();
            for(int cur = u; cur != next; cur = parent[cur]){
                newCyc.pb(edge[cur]);
                edgeList[edge[cur]].cycInd = cycle.size();
            }
            cycle.pb(newCyc);
        }
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    MaxFlow MF(2*m + 5);
    graph.assign(n, vector<int>());
    rep(i, 0, m - 1){
        int a, b, c; cin >> a >> b >> c; a--; b--; c--;
        edgeList.pb({a, b, c, -1});
        graph[a].pb(i);
        graph[b].pb(i);
    }
    parent.assign(n, -1);
    edge.assign(n, -1);
    d.assign(n, -1);
    d[0] = 0;
    detectCycle(0);
    //debug(cycle.size());
    rep(i, 0, m - 1){
        if(edgeList[i].cycInd == -1){
            edgeList[i].cycInd = cycle.size();
            cycle.pb(vector<int>(1, i));
        }
    }
    rep(i, 0, m - 1){
        MF.addEdge(2*m, i, 1);
        MF.addEdge(edgeList[i].c, edgeList[i].cycInd + m, 1);
    }
    rep(i, 0, cycle.size() - 1){
        MF.addEdge(i + m, 2*m + 1, max(1, (int)cycle[i].size() - 1));
    }
    rep(i, 0, cycle.size() - 1){
        rep(j, 0, cycle[i].size() - 1){
            cout << cycle[i][j] << " ";
        }
        cout << endl;
    }
    //MF.printGraph();
    cout << MF.findMaxFlow(2*m, 2*m + 1);
    return 0;
}


