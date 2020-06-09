//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2501
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

struct Edge{
    int v, rev, c, f;
};

const int N = 60;
int m, w;
vector<Edge> g[2*N + 6];


class MaxFlow{
private:
    vi delta, pNode, pEdge;

    bool bfs(int s, int t){
        delta.assign(2*N + 6, inf);
        pNode.assign(2*N + 6, -1);
        pEdge.assign(2*N + 6, -2);
        queue<int> q; q.push(s);
        vector<bool> visited; visited.resize(2*N + 6, 0);
        visited[s] = 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(visited[e.v] || e.c - e.f == 0) continue;
                visited[e.v] = 1;
                q.push(e.v);
                delta[e.v] = min(delta[u], e.c - e.f);
                pNode[e.v] = u;
                pEdge[e.v] = i;
            }
        }
        return visited[t];
    }

    int increaseFlow(int s, int t){
        int df = delta[t];
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            g[node][edge].f += df;
            g[cur][g[node][edge].rev].f -= df;
            //a[cur].f += df;
            //cout << cur << " ";
        }
        //debug(df);
        return df;
    }

public:
    void addEdge(int s, int t, int c){
        g[s].pb({t, g[t].size(), c, 0});
        g[t].pb({s, g[s].size() - 1, 0, 0});
    }

    int findMaxFlow(int s, int t){
        int maximumFlow = 0;
        while(bfs(s, t)){
            maximumFlow += increaseFlow(s, t);
        }
        /*rep(i, 1, m){
            cout << i << " " << a[i].c << " " << a[i].f << endl;
            rep(j, 0, g[i].size() - 1){
                cout << g[i][j].v << " " << g[i][j].c << " " << g[i][j].f << endl;
            }
            cout << endl;
        }*/
        return maximumFlow;
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    //freopen("angry_programmer.txt","r",stdin);
    while(true){
        rep(i, 0, 2*N + 5){
            g[i].clear();
        }
        cin >> m >> w;
        MaxFlow MF;
        if(m == 0 && w == 0) break;
        rep(i, 1, m - 2){
            int x, y; cin >> x >> y;
            MF.addEdge(x, x + N, y);
            MF.addEdge(x + N, x, y);
        }
        MF.addEdge(1, 1 + N, inf);
        MF.addEdge(m, m + N, inf);
        MF.addEdge(1 + N, 1, inf);
        MF.addEdge(m + N, m, inf);
        rep(i, 1, w){
            int j, k, d; cin >> j >> k >> d;
            MF.addEdge(j + N, k, d);
            MF.addEdge(k + N, j, d);
        }
        //int ans = MF.findMaxFlow(1, m);
        //cout << ans;
        cout << MF.findMaxFlow(1, m) << endl;
    }
    return 0;
}
