//https://codeforces.com/problemset/problem/847/J
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

const int N = 5005;

vii edgeList;

struct Edge{
    int v, rev, c, f;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi level, pos;
    vii ans;

    bool dinic_bfs(int s){
        level.assign(n, -1);
        level[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(level[e.v] == -1 && e.c - e.f > 0){
                    q.push(e.v);
                    level[e.v] = level[u] + 1;
                }
            }
        }
        return (level[t] != -1);
    }

    int dinic_dfs(int u, int f){
        if(u == t) return f;
        for(; pos[u] < g[u].size(); pos[u]++){
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
            cout << i << endl;
            rep(j, 0, (int)g[i].size() - 1){
                cout << g[i][j].v << " " << g[i][j].c << endl;
            }
            cout << endl;
        }
    }

    void addEdge(int u, int v, int c){
        g[u].pb({v, g[v].size(), c, 0});
        g[v].pb({u, g[u].size() - 1, 0, 0});
    }

    int getMaxFlow(int s, int t, int c){
        this->t = t;
        int maxFlow = 0;
        rep(i, 0 , g[n - 2].size() - 1){
            g[n - 2][i].c = c;
        }
        rep(i, 0, n - 1){
            rep(j, 0, g[i].size() - 1){
                g[i][j].f = 0;
            }
        }
        while(dinic_bfs(s)){
            int df;
            pos.assign(n, 0);
            while(df = dinic_dfs(s, inf)){
                maxFlow += df;
            }
        }
        return maxFlow;
    }

    void findGift(int u){
        int maxGift = 0;
        rep(i, 0, g[u].size() - 1){
            maxGift = max(maxGift, g[u][i].f);
        }
        cout << maxGift;
    }

    void saveList(int node, int edge){
        ans.clear();
        rep(i, 0, node - 1){
            rep(j, 0, g[i].size() - 1){
                Edge e = g[i][j];
                if(e.f == 1){
                    ans.pb({i + 1, (edgeList[e.v - node].first + 1 + edgeList[e.v - node].second + 1 - (i + 1))});
                }
            }
        }
    }

    void printList(){
        rep(i, 0, ans.size() - 1){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    /*bool checkPair(int node){
        rep(i, 0, g[n - 2].size() - 1){
            if(g[node + i][n - 1].f == 0) return false;
        }
        return true;
    }*/
};

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    if(m == 0) {
        cout << 0; return 0;
    }

    MaxFlow MF(n + m + 2);
    rep(i, 0, m - 1){
        int x, y; cin >> x >> y; x--; y--;
        MF.addEdge(x, n + i, 1);
        MF.addEdge(y, n + i, 1);
        edgeList.pb({x, y});
    }
    rep(i, 0, n - 1){
        MF.addEdge(n + m, i, inf);
    }
    rep(i, 0, m - 1){
        MF.addEdge(n + i, n + m + 1, 1);
    }
    int left = 1, right = m, mid, ans;
    while(left <= right){
        mid = left + (int)(right - left)/2;
        //cout << left << " " << right << endl;
        //debug(mid);
        int maxFlow = MF.getMaxFlow(n + m, n + m + 1, mid);
        //debug(maxFlow);
        if(maxFlow != m){
            left = mid + 1;
        }else{
            right = mid - 1;
            ans = mid;
            MF.saveList(n, m);
        }
    }
    //MF.printGraph();
    cout << ans << endl;
    MF.printList();
    //MF.findGift(2*n);
    return 0;
}

