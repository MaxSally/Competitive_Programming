//http://codeforces.com/problemset/problem/884/F
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
int cntChar[30];

struct Edge{
    int v, rev, cap, f, cost;
};

class MaxFlow{
private:
    int n, t;
    vi pNode, pEdge, dist;
    vector<vector<Edge> > g;

    bool longest_path_fast_algo(int s){
        queue<int> q; q.push(s);
        vector<bool> inQueue(n, 0);
        inQueue[s] = 1;
        pNode.assign(n, -1);
        pEdge.assign(n, -1);
        dist.assign(n, inf);
        dist[s] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            inQueue[u] = 0;
            rep(i, 0, (int)g[u].size() - 1){
                Edge &e = g[u][i];
                if(e.cap - e.f == 0) continue;
                if(dist[u] + e.cost < dist[e.v]){
                    dist[e.v] = e.cost + dist[u];
                    pNode[e.v] = u;
                    pEdge[e.v] = i;
                    if(!inQueue[e.v]){
                        inQueue[e.v] = 1;
                        q.push(e.v);
                    }
                }
            }
        }
        //debuga1(dist, 0, n - 1);
        return (dist[t] != inf);
    }

    pair<int, int> increaseFlow(int s){
        int df = inf, totalCost = 0;
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            Edge e = g[node][edge];
            df = min(df, e.cap - e.f);
        }
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur], edge = pEdge[cur];
            Edge &e = g[node][edge];
            e.f += df;
            g[cur][e.rev].f -= df;
            totalCost += df*e.cost;
        }
        //debug(df);
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

    pair<int,int> getFlowAndCost(int s, int t){
        int maxFlow = 0, totalCost = 0;
        this->t = t;
        while(longest_path_fast_algo(s)){
            pair<int,int> ans = increaseFlow(s);
            maxFlow += ans.first;
            totalCost += ans.second;
            //debug(maxFlow);
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
    int n;
    cin >> n;
    string s; cin >> s;
    vector<int> b(n, 0);
    mem(cntChar, 0);
    rep(i, 0, n - 1){
        cin >> b[i];
        cntChar[s[i] - 'a']++;
    }
    //debuga1(cntChar, 0, 25);
    //debug(n);
    MaxFlow MF(26 + n/2 + 2);
    rep(i, 0, 25){
        MF.addEdge(26 + n/2, i, cntChar[i], 0);
    }
    rep(i, 0, n/2 - 1){
        MF.addEdge(26 + i, 26 + n/2 + 1, 2, 0);
    }
    //Flag(0);
    int length = (int)s.length()/2 - 1;
    rep(i, 0, length){
        int a = s[i] - 'a';
        int c = s[n - i - 1] - 'a';
        if(a == c){
            MF.addEdge(a, 26 + i, 1, -1*max(b[i], b[n - i - 1]));
        }else{
            MF.addEdge(a, 26 + i, 1, -b[i]);
            MF.addEdge(c, 26 + i, 1, -b[n - i - 1]);
        }
        rep(j, 0, 25){
            if(a == j || c == j){
                continue;
            }else{
                MF.addEdge(j, 26 + i, 1, 0);
            }
        }
    }
    //Flag(1);
    //MF.printGraph();
    pair<int,int> ans = MF.getFlowAndCost(26 + n/2, 26 + n/2 + 1);
    //MF.printGraph();
    cout << -ans.second;
    return 0;
}
