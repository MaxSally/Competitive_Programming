//https://codeforces.com/problemset/problem/802/N
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
#define inf (ll) (1e10 + 7)
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

const int N = 2205;

struct Edge{
    int v, rev, cap, f;
    ll cost;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pNode, pEdge;
    vl dist;

    bool shortest_path_fast_algorithm(int s){
        queue<int> q; q.push(s);
        vector<bool> inQueue(n, 0);
        pNode.assign(n, -1);
        pEdge.assign(n, -1);
        dist.assign(n, inf);
        dist[s] = 0ll;
        inQueue[s] = 1;
        while(q.size()){
            int u = q.front(); q.pop();
            inQueue[u] = 0;
            //debug(u);
            //debuga1(dist, 1, n - 1);
            rep(i, 0, g[u].size() - 1){
                Edge &e = g[u][i];
                if(e.cap - e.f == 0) continue;
                if(dist[u] + e.cost < dist[e.v]){
                    dist[e.v] = dist[u] + e.cost;
                    pNode[e.v] = u;
                    pEdge[e.v] = i;
                    if(!inQueue[e.v]){
                        inQueue[e.v] = 1;
                        q.push(e.v);
                    }
                }
            }
        }
        return (dist[t] != inf);
    }

    pair<int, ll> increaseFlow(int s){
        int df = (int)inf;
        ll totalCost = 0;
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            df = min(df, g[node][edge].cap - g[node][edge].f);
        }
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            Edge &e = g[node][edge];
            e.f += df;
            g[cur][e.rev].f -= df;
            totalCost += (1LL*df*e.cost);
        }
        return {df, totalCost};
    }

public:
    MaxFlow(int n){
        this-> n = n;
        g.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int cap, ll cost){
        g[u].pb({v, (int)g[v].size(), cap, 0, cost});
        g[v].pb({u, (int)g[u].size() - 1, 0, 0, -cost});
    }

    pair<int, ll> getFlowAndCost(int s, int t){
        this->t = t;
        int maxFlow = 0;
        ll totalCost = 0LL;
        while(shortest_path_fast_algorithm(s)){
            pair<int, ll> ans = increaseFlow(s);
            maxFlow += ans.first;
            totalCost += ans.second;
        }
        return {maxFlow, totalCost};
    }

    void printGraph(){
        rep(i, 0, n - 1){
            //debug(i); debug(g[i].size());
            cout << i << endl;
            rep(j, 0, (int)g[i].size() - 1){
                Edge e = g[i][j];
                cout << e.v << " " << e.cap << " " << e.f << " " << e.cost << endl;
            }
            cout << endl;
        }
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    MaxFlow MF(n + 3);
    MF.addEdge(n + 2, 0, k, 0);
    rep(i, 1, n - 1){
        MF.addEdge(i, i + 1, k, 0);
    }
    rep(i, 1, n){
        cin >> a[i];
        MF.addEdge(0, i, 1, a[i]);
    }
    rep(i, 1, n){
        cin >> b[i];
        MF.addEdge(i, n + 1, 1, b[i]);
    }
    pair<int, ll> ans = MF.getFlowAndCost(n + 2, n + 1);
    //MF.printGraph();
    cout << ans.second;
    return 0;
}


