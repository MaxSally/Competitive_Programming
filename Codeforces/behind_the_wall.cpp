//https://codeforces.com/gym/101149/problem/D
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

const int N = 55;
int graph[N][N];
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

struct Edge{
    int v, rev, c, f;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pNode, pEdge, delta;

    void dfs(vector<bool> &visited, int s){
        visited[s] = 1;
        rep(i, 0, g[s].size() - 1){
            Edge e = g[s][i];
            if(e.c - e.f > 0 && !visited[e.v]){
                dfs(visited, e.v);
                //Flag(1);
            }
        }
    }

    bool bfs(int s){
        queue<int> q; q.push(s);
        vector<bool> visited(n, 0);
        visited[s] = 1;
        pNode.assign(n, -1);
        pEdge.assign(n, -2);
        delta.assign(n, inf);
        while(q.size()){
            int u = q.front(); q.pop();
            //debug(u);
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(visited[e.v] || e.c - e.f == 0) continue;
                delta[e.v] = min(delta[u], e.c - e.f);
                pNode[e.v] = u;
                pEdge[e.v] = i;
                q.push(e.v);
                visited[e.v] = 1;
            }
        }
        return visited[t];
    }

    int increaseFlow(int s){
        int df = delta[t];
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            g[node][edge].f += df;
            g[cur][g[node][edge].rev].f -= df;
        }
        return df;
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

    int getMaxFlow(int s, int t){
        this->t = t;
        int maxFlow = 0;
        while(bfs(s)){
            maxFlow += increaseFlow(s);
        }
        return maxFlow;
    }

    void printGraph(){
        rep(i, 0, n - 1){
            //debug(i); debug(g[i].size());
            cout << "i: " << i << endl;
            rep(j, 0, (int)g[i].size() - 1){
                cout << g[i][j].v << " " << g[i][j].c << " " << g[i][j].f << endl;
            }
        }
    }

    void printMap(int l, int w, int r, int c){
        vector<bool> visited(n, 0);
        dfs(visited, 2*l*w);
        /*rep(i, 0, n - 1){
            cout << i << " " << visited[i] << endl;
        }*/
        rep(i, 0, l - 1){
            rep(j, 0, w - 1){
                if(i == r && j == c){
                    cout << '.'; continue;
                }
                int node = i*w + j;
                if(!visited[node + l * w] && visited[node]){
                    cout << 'X';
                }else{
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, m, r, c; cin >> n >> m >> r >> c; r--; c--;
    MaxFlow MF(2*n*m + 2);
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            cin >> graph[i][j];
            if(i == r && j == c) continue;
            MF.addEdge(i*m + j, i*m + j + m*n, graph[i][j]);
        }
    }
    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            if(i == r && j == c) continue;
            rep(k, 0, 3){
                int x1 = i + x[k], y1 = j + y[k];
                if(x1 < 0 || x1 > n - 1 || y1 < 0 || y1 > m - 1) continue;
                MF.addEdge(i*m + j + n*m, x1*m + y1, inf);
            }
        }
    }
    rep(i, 0, n - 1){
        MF.addEdge(2*n*m, i*m, inf);
        MF.addEdge(2*n*m, i*m + m - 1, inf);
    }
    rep(i, 1, m - 2){
        MF.addEdge(2*n*m, i, inf);
        MF.addEdge(2*n*m, i + (n - 1)*m, inf);
    }
    int ans = MF.getMaxFlow(2*n*m, r*m + c);
    cout << ans << endl;
    //MF.printGraph();
    MF.printMap(n, m, r, c);
    return 0;
}

