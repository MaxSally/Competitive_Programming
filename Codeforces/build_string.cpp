//https://codeforces.com/problemset/problem/237/E?fbclid=IwAR2QC60ob0QJzWyPcDwRXX8h7sBY5nXAJBbo699ET19oIk6CMsRHYbf57TM
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

const int N = 105;
int mark[26];

struct Edge{
    int v, rev, cap, f, cost;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pNode, pEdge, delta, dist;

    bool shortest_path_fast_algorithm(int s){
        queue<int> q; q.push(s);
        vector<bool> inQueue(n, 0);
        pNode.assign(n, -1);
        pEdge.assign(n, -2);
        dist.assign(n, inf);
        inQueue[s] = 1;
        dist[s] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            inQueue[u] = 0;
            //debug(u);
            rep(i, 0, g[u].size() - 1){
                Edge &e = g[u][i];
                if(e.cap - e.f == 0)continue;
                if(dist[u] + e.cost < dist[e.v]){
                    dist[e.v] = dist[u] + e.cost;
                    pNode[e.v] = u;
                    pEdge[e.v] = i;
                    if(!inQueue[e.v]){
                        q.push(e.v);
                        inQueue[e.v] = 1;
                    }
                }
            }
        }
        return (dist[t] != inf);
    }

    pair<int,int> increaseFlow(int s){
        int df = inf, totalCost = 0;
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            df = min(df, g[node][edge].cap - g[node][edge].f);
        }
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            g[node][edge].f += df;
            g[cur][g[node][edge].rev].f -= df;
            totalCost += df * g[node][edge].cost;
        }
        return {df, totalCost};
    }

public:
    MaxFlow(int n){
        this-> n = n;
        g.assign(n + 1, vector<Edge>());
    }
    void addEdge(int u, int v, int cap, int cost){
        g[u].pb({v, g[v].size(), cap, 0, cost});
        g[v].pb({u, g[u].size() - 1, 0, 0, - cost});
    }

    pair<int,int> findMaxFlow(int s, int t){
        this->t = t;
        int maxFlow = 0, totalCost = 0;
        while(shortest_path_fast_algorithm(s)){
            pair<int,int> ans = increaseFlow(s);
            maxFlow += ans.first;
            totalCost += ans.second;
            //debug(maxFlow);
            //debug(totalCost);
        }
        return {maxFlow, totalCost};
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

};

int main(){
    io
    freopen("input.txt","r",stdin);
    string t;
    cin >> t;
    int length = t.length();
    int n; cin >> n;
    MaxFlow MF(26 + n + 2);
    mem(mark, 0);
    rep(i, 0, length - 1){
        mark[t[i] - 'a']++;
    }
    rep(i, 0, 25){
        if(mark[i])
            MF.addEdge(n + 26, i, mark[i], 0);
    }
    rep(i, 0, n - 1){
        cin >> t;
        int a; cin >> a;
        mem(mark, 0);
        rep(j, 0, t.length() - 1){
            mark[t[j] - 'a']++;
        }
        //debuga1(mark, 0, 25);
        rep(j, 0, 25){
            if(mark[j])
                MF.addEdge(j, 26 + i, mark[j], 0);
        }
        MF.addEdge(26 + i, 26 + n + 1, a, i + 1);
    }
    //MF.printGraph();
    pair<int,int> ans = MF.findMaxFlow(26 + n, 26 + n + 1);
    if(ans.first != length)
        cout << -1;
    else
        cout << ans.second;
    return 0;
}
