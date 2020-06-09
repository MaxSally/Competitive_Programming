//https://codeforces.com/problemset/problem/717/G
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

struct Edge{
    int v, rev, cap, f, cost;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pEdge, pNode, dist;

    bool longest_path_fast_algorithm(int s){
        pEdge.assign(n, -1);
        pNode.assign(n, -1);
        dist.assign(n, inf);
        vector<bool> inQueue(n, 0);
        queue<int> q; q.push(s);
        inQueue[s] = 1;
        dist[s] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            inQueue[u] = false;
            //debug(u);
            rep(i, 0, g[u].size() - 1){
                Edge &e = g[u][i];
                if(e.cap - e.f == 0) continue;
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
            totalCost += df*g[node][edge].cost;
        }
        return {df, totalCost};
    }

public:

    MaxFlow(int n){
        this-> n = n;
        g.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int cap, int cost){
        g[u].pb({v, g[v].size(), cap, 0, cost});
        g[v].pb({u, g[u].size() - 1, 0, 0, -cost});
    }

    pair<int,int> getFlowandCost(int s, int t){
        this->t = t;
        int totalCost = 0, maxFlow = 0;
        while(longest_path_fast_algorithm(s)){
            pair<int, int> ans = increaseFlow(s);
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
            cout << i << endl;
            rep(j, 0, (int)g[i].size() - 1){
                cout << g[i][j].v << " " << g[i][j].cap << " " << g[i][j].f << " " << g[i][j].cost << endl;
            }
            cout << endl;
        }
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, m, p, x;
    string s, t;
    vector<pair<string, int> > wordList;
    cin >> n >> s >> m;
    rep(i, 1, m){
        cin >> t >> p;
        wordList.pb(make_pair(t, p));
    }
    cin >> x;
    MaxFlow MF(n + 2);
    rep(i, 0, n){
        MF.addEdge(i, i + 1, x, 0);
    }
    rep(i, 0, m - 1){
        t = wordList[i].first;
        p = wordList[i].second;
        int length = t.length();
        rep(j, 0, n - 1 - length + 1){
            bool flag = 1;
            rep(k, 0, length - 1){
                if(t[k] != s[j + k]){
                    flag = 0; break;
                }
            }
            if(flag){
                MF.addEdge(j + 1, j + 1 + length, 1, - p);
            }
        }
    }
    pair<int, int> ans = MF.getFlowandCost(0, n + 1);
    //MF.printGraph();
    cout << -ans.second;
    return 0;
}

