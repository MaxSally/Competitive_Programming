//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=761
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

const int N = 1005;

struct Edge{
    int v, rev, c, f; //v = end node, rev = the reverse edge, c = capacity, f = current flow
    Edge(int v, int rev, int c, int f){
        this->v = v; this->rev = rev; this->c = c; this->f = f;
    }
};

class MaxFlow{
private:
    int n;
    vector<vector<Edge> > graph;
    vi delta, pNode, pEdge;

    void printGraph(){
        rep(i, 0, n - 1){
            cout << i << " ";
            rep(j, 0 , graph[i].size() - 1){
                cout << graph[i][j].v << " ";
            }
            cout << endl;
        }
    }
    bool findPath(int s, int t){
        //printGraph();
        queue<int> q;
        q.push(s);
        delta.assign(n, inf);
        pNode.assign(n, -1);
        pEdge.assign(n, -3);
        vector<bool> visited; visited.resize(n, false);
        visited[s]= 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < graph[u].size(); i++){
                //cout << "hello" << endl;
                Edge e = graph[u][i];
                if(visited[e.v] || (e.c - e.f) == 0) continue;
                q.push(e.v);
                visited[e.v] = 1;
                delta[e.v] = min(delta[u], e.c - e.f);
                pNode[e.v] = u;
                pEdge[e.v] = i;
            }
        }
        return visited[t];
    }

    int increaseFlow(int u, int v){
        int df = delta[v];
        for(int cur = v; cur != u; cur = pNode[cur]){
            //cout << cur << endl;
            int edge = pEdge[cur], node = pNode[cur];
            graph[node][edge].f += df;
            graph[cur][graph[node][edge].rev].f -= df;
        }
        return df;
    }
public:

    MaxFlow(int n){
        this->n = n;
        graph.assign(n, vector<Edge>());
    }


    void addEdge(int u, int v, int c){
        graph[u].pb(Edge(v, graph[v].size(), c, 0));
        graph[v].pb(Edge(u, graph[u].size() - 1, 0, 0));
    }

    int findMaxFlow(int s, int t){
        int maximumFlow = 0;
        while(findPath(s, t)){
            maximumFlow += increaseFlow(s, t);
        }
        return maximumFlow;
    }
};

int main(){
    io
    freopen("input.txt","r",stdin);
    int cnt = 0;
    int n, s, t, c;
    while(true){
        cnt++;
        cin >> n;
        if(n == 0) break;
        cin >> s >> t >> c;
        MaxFlow MF(n);
        rep(i, 1, c){
            int u, v, cap;
            cin >> u >> v >> cap;
            MF.addEdge(u - 1, v - 1, cap);
            MF.addEdge(v - 1, u - 1, cap);
        }
        cout << "Network " << cnt << endl;
        cout << "The bandwidth is " << MF.findMaxFlow(s - 1, t - 1) << "." << endl << endl;
    }
    return 0;
}
