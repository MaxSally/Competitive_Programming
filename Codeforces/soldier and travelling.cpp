//https://codeforces.com/problemset/problem/546/E
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
#define debuga1(a, l, r) fo(i, l, r, 1) cout << a[i] << " "; cout << endl
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

const int N = 105;
int n, m, a[2*N], b[2*N], ans[N + 5][N + 5];
vector<Edge> g[205];

class MaxFlow{
private:
    vi delta, pNode, pEdge;

    bool bfs(int s, int t){
        delta.assign(2*N, inf);
        pNode.assign(2*N, -1);
        pEdge.assign(2*N, -2);
        vector<bool> visited; visited.resize(2*N, 0);
        queue<int> q; q.push(s);
        visited[s] = 1;
        while(!q.empty()){
            //cout << "here" << endl;
            int u = q.front(); q.pop();
            //cout << u << endl;
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(visited[e.v] || e.c - e.f == 0) continue;
                visited[e.v] = 1; q.push(e.v);
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
        }
        return df;
    }

public:
    void addEdge(int u, int v, int c){
        g[u].pb({v, g[v].size(), c, 0});
        g[v].pb({u, g[u].size() - 1, 0, 0});
    }

    int findMaxFlow(int s, int t){
        int maximumFlow = 0;
        while(bfs(s, t)){
            maximumFlow += increaseFlow(s, t);
        }
        return maximumFlow;
    }

    bool isValid(){
        /*rep(i, 100, 100 + n - 1){
            rep(j, 0, g[i].size() - 1){
                cout << i << " " << g[i][j].v << " " << g[i][j].c << " " << g[i][j].f << endl;
            }
        }*/
        rep(i, 100, 100 + n - 1){
            rep(j, 0, g[i].size() - 1){
                if(g[i][j].v == 202 && g[i][j].c != g[i][j].f){
                    //cout << g[i][j].c << " " << g[i][j].f << endl;
                    return false;
                }
            }
        }
        rep(j, 0, g[201].size() - 1){
            if(g[201][j].c != g[201][j].f){
                //cout << g[i][j].c << " " << g[i][j].f << endl;
                return false;
            }
        }
        return true;
    }

};


int main(){
    io
    freopen("input.txt","r",stdin);
    MaxFlow MF;
    cin >> n >> m;
    rep(i, 0, n - 1){
        cin >> a[i];
        MF.addEdge(201, i, a[i]);
        MF.addEdge(i, i + 100, a[i]);
    }
    rep(i, 0, n - 1){
        cin >> b[i];
        MF.addEdge(i + 100, 202, b[i]);
    }
    rep(i, 0, m - 1){
        int s, t; cin >> s >> t; s--; t--; MF.addEdge(s, t + 100, a[s]); MF.addEdge(t, s + 100, a[t]);
    }
    int maxFlow = MF.findMaxFlow(201, 202);
    if(MF.isValid()){
        cout << "YES" << endl;
        rep(i, 0, n - 1){
            rep(j, 0, (int) g[i].size() - 1){
                if(g[i][j].v != 201){
                    ans[i][g[i][j].v - 100] = g[i][j].f;
                }
            }
        }
        rep(i, 0, n - 1){
            rep(j, 0, n - 1){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << "NO";
    }
    return 0;
}

