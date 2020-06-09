//http://codeforces.com/contest/277/problem/E
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
#define inf (double) (1e9 + 7)
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

const int N = 405;

struct Edge{
    int v, rev, cap, f;
    double cost;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pNode, pEdge;
    vector<double> dist;

    bool shortest_path_fast_algo(int s){
        queue<int> q; q.push(s);
        pNode.assign(n, -1);
        pEdge.assign(n, -1);
        dist.assign(n, inf);
        dist[s] = 0.0;
        vector<bool> inQueue(n, 0);
        inQueue[s] = 1;
        while(q.size()){
            int u = q.front(); q.pop();
            inQueue[u] = 0;
            //debug(u);
            rep(i, 0, g[u].size() - 1){
                Edge &e = g[u][i];
                if(e.cap - e.f == 0) continue;
                if(-dist[e.v] + dist[u] + e.cost < 0.0){
                    dist[e.v] = dist[u] + e.cost;
                    pNode[e.v] = u;
                    pEdge[e.v] = i;
                    if(!inQueue[e.v]){
                        inQueue[e.v] = 1;
                        q.push(e.v);
                    }
                    //debuga1(dist, 0, n - 1);
                }
            }
        }
        //debuga1(dist, 0, n - 1);
        return (inf - dist[t] > 1e-9);
    }

    pair<int,double> increaseFlow(int s){
        int df = (int) (1e9 + 7);
        double totalCost = 0.0;
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur]; int edge = pEdge[cur];
            Edge &e = g[node][edge];
            df = min(df, e.cap - e.f);
        }
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur]; int edge = pEdge[cur];
            Edge &e = g[node][edge];
            e.f += df;
            g[cur][e.rev].f -= df;
            totalCost += 1.0*e.cost*df;
        }
        return{df, totalCost};
    }

public:
    MaxFlow(int n){
        this->n = n;
        g.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int cap, double cost){
        g[u].pb({v, g[v].size(), cap, 0, cost});
        g[v].pb({u, g[u].size() - 1, 0, 0, -cost});
    }

    pair<int, double> getFlowAndCost(int s, int t){
        this->t = t;
        int maxFlow = 0;
        double totalCost = 0.0;
        while(shortest_path_fast_algo(s)){
            pair<int, double> ans = increaseFlow(s);
            maxFlow += ans.first;
            totalCost += ans.second;
            //debug(totalCost);
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

double distance(pair<int,int> &a, pair<int,int> &b){
    return (sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second)));
}

int main(){
    io
    //#ifdef MAXNGUYEN
    freopen("input.txt","r",stdin);
    //#endif
    int n;
    cin >> n;
    vii pnt;
    MaxFlow MF(2*n + 2);
    rep(i, 0, n - 1){
        int x, y; cin >> x >> y;
        pnt.pb({x, y});
    }
    rep(i, 0, n - 1){
        rep(j, 0, n - 1){
            if(pnt[i].second > pnt[j].second){
                MF.addEdge(i, n + j, 1, distance(pnt[i], pnt[j]));
            }
        }
    }
    rep(i, 0, n - 1){
        MF.addEdge(2*n, i, 2, 0.0);
        MF.addEdge(n + i, 2*n + 1, 1, 0.0);
    }
    pair<int, double> ans = MF.getFlowAndCost(2*n, 2*n + 1);
    //MF.printGraph();
    if(ans.first == n - 1)
        cout << fixed << setprecision(9) << ans.second;
    else
        cout << -1;
    return 0;
}

