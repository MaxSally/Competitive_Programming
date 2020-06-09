//https://codeforces.com/problemset/problem/498/C
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
#define flagHere cout << "here" << endl;
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
    int v, rev, c, f;
};

vector<Edge> g[N];
int n, m, a[N], p[N], q[N], numPow[N];

class MaxFlow{
private:
    vi pNode, pEdge, delta;

    bool bfs(int s, int t){
        queue<int> q; q.push(s);
        vector<bool> visited; visited.resize(N, 0); visited[s] = 1;
        delta.assign(N, inf); pNode.assign(N, -1); pEdge.assign(N, -2);
        while(!q.empty()){
            //debuga1(visited, 0, N - 1);
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                //flagHere
                if(visited[e.v] || e.c - e.f == 0) continue;
                visited[e.v] = 1;
                q.push(e.v);
                delta[e.v] = min(delta[u], e.c - e.f);
                pEdge[e.v] = i;
                pNode[e.v] = u;
            }
        }
        /*rep(i, 0, N - 1){
            if(g[i].size()){
                cout << i << endl;
                rep(j, 0, g[i].size() - 1){
                    cout << g[i][j].v << " " << g[i][j].c << " " << g[i][j].f << endl;
                }
                cout << endl;
            }
        }*/
        return visited[t];
    }

    int increaseFlow(int s, int t){
        double df = delta[t];
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            g[node][edge].f += df;
            g[cur][g[node][edge].rev].f -= df;
        }
        return delta[t];
    }

public:
    void addEdge(int u, int v, int c){
        g[u].pb({v, g[v].size(), c, 0});
        g[v].pb({u, g[u].size() - 1, 0, 0});
    }

    int findMaxFlow(int div){
        mem(numPow, 0);
        rep(i, 0, n){
            g[i].clear();
        }
        rep(i, 1, n){
            while(a[i] % div == 0){
                a[i] /= div;
                numPow[i]++;
            }
        }
        rep(i, 1, m){
            addEdge(p[i], q[i], min(numPow[p[i]], numPow[q[i]]));
        }
        rep(i, 1, n){
            if(i % 2){
                addEdge(0, i, numPow[i]);
            }else{
                addEdge(i, n + 1, numPow[i]);
            }
        }
        int maximumFlow = 0;
        int s = 0, t = n + 1;
        while(bfs(s, t)){
            maximumFlow += increaseFlow(s, t);
        }
        return maximumFlow;
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    MaxFlow MF;
    rep(i, 1, n){
        cin >> a[i];
    }
    rep(i, 1, m){
        cin >> p[i] >> q[i];
        if(q[i] % 2) swap(p[i], q[i]);
    }
    int res = 0;
    rep(i, 1, n){
        rep(j, 2, (int) sqrt(a[i])){
            if(a[i] % j == 0)
                res += MF.findMaxFlow(j);
        }
        if(a[i] > 1) res += MF.findMaxFlow(a[i]);
    }
    cout << res;
    return 0;
}

