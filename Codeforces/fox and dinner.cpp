//https://codeforces.com/problemset/problem/510/E
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

const int N = 205;
bool isPrime[40005];

void sieve(){
    fill(isPrime, isPrime + 40005, true);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < 40005; i++){
        if(isPrime[i]){
            for(int j = 2*i; j < 40005; j += i){
                isPrime[j] = 0;
            }
        }
    }
}


struct Edge{
    int v, rev, c, f;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vvi graph;
    vi pNode, pEdge, delta;

    int bfs(int s){
        queue<int> q; q.push(s);
        vector<bool> visited(n, 0);
        pNode.assign(n, -1);
        pEdge.assign(n, -1);
        delta.assign(n, inf);
        visited[s] = 1;
        while(q.size()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge &e = g[u][i];
                if(visited[e.v] || e.c - e.f == 0)continue;
                visited[e.v] = 1;
                q.push(e.v);
                pNode[e.v] = u;
                pEdge[e.v] = i;
                delta[e.v] = min(delta[u], e.c - e.f);
            }
        }
        return (delta[t] != inf);
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

    void dfs(vector<int> &parent, vector<bool> &visited, int u, int pre){
        visited[u] = 1;
        parent.pb(u);
        rep(i, 0, (int)graph[u].size() - 1){
            int v = graph[u][i];
            if(v == pre) continue;
            if(visited[v]){
                return;
            }
            dfs(parent, visited, v, u);
        }
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

    int getFlow(int s, int t){
        this-> t = t;
        int maxFlow = 0;
        while(bfs(s)){
            maxFlow += increaseFlow(s);
        }
        return maxFlow;
    }

    void getGraph(vector<int> &a){
        int sz = (int)a.size();
        graph.assign(sz, vector<int>());
        rep(i, 0 , sz - 1){
            if(a[i] % 2){
                rep(j, 0, g[i].size() - 1){
                    Edge &e = g[i][j];
                    if(e.c > 0 && e.c - e.f == 0){
                        graph[i].pb(e.v);
                        graph[e.v].pb(i);
                    }
                }
            }
        }
        /*rep(i, 0, sz - 1){
            cout << i << " ";
            rep(j, 0, (int)graph[i].size() - 1){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }*/
        vector<bool> visited(n, 0);
        vvi ans;
        rep(i, 0, sz - 1){
            if(visited[i])continue;
            vector<int> parent;
            dfs(parent, visited, i, -1);
            ans.pb(parent);
        }
        cout << (int)ans.size() << endl;
        rep(i, 0, ans.size() - 1){
            vector<int> parent = ans[i];
            cout << (int)parent.size() << " ";
            rep(j, 0, (int)parent.size() - 1){
                cout << parent[j] + 1 << " ";
            }
            cout << endl;
        }
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
};

int main(){
    io
    freopen("input.txt","r",stdin);
    sieve();
    //debuga1(isPrime, 0, 100);
    int n, even, odd; even = odd = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    //sort(a.begin(), a.end());
    MaxFlow MF(n + 2);
    rep(i, 0, n - 1){
        if(a[i] % 2){
            MF.addEdge(n, i, 2);
            odd++;
        }else{
            MF.addEdge(i, n + 1, 2);
            even++;
        }
    }
    if(even != odd){
        cout << "Impossible"; return 0;
    }
    rep(i, 0, n - 2){
        rep(j, i + 1, n - 1){
            if(isPrime[a[i] + a[j]]){
                if(a[i] % 2)
                    MF.addEdge(i, j, 1);
                else
                    MF.addEdge(j, i, 1);
            }
        }
    }
    int ans = MF.getFlow(n, n + 1);
    //cout << ans << endl;
    //MF.printGraph();
    if(ans != n){
        cout << "Impossible"; return 0;
    }
    MF.getGraph(a);
    return 0;
}

