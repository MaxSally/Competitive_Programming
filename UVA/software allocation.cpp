//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=195
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

const int N = 1000;

struct Edge{
    int v, rev, c, f;
    Edge(int v, int rev, int c, int f){
        this->v = v; this-> rev = rev; this->c = c; this->f = f;
    }
};

vector<Edge> g[40];
int ans[15];

class MaxFlow{
private:
    int n = 40;
    vi pNode, pEdge, delta;

    bool bfs(int s, int t){
        queue<int> q;
        q.push(s);
        vector<bool> visited; visited.resize(n, 0);
        pNode.assign(n, -1);
        pEdge.assign(n, -2);
        delta.assign(n, inf);
        visited[s] = 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(visited[e.v] || e.c - e.f == 0) continue;
                q.push(e.v);
                visited[e.v] = 1;
                delta[e.v] = min(delta[u], e.c - e.f);
                pNode[e.v] = u;
                pEdge[e.v] = i;
            }
        }
        //rep(i, 0, 39) cout << visited[i] << " ";
        //cout << endl;
        return visited[t];
    }

    int increaseFlow(int s, int t){
        int df = delta[t];
        for(int cur = t; cur != s; cur = pNode[cur]){
            int node = pNode[cur];
            int edge = pEdge[cur];
            g[node][edge].f += df;
            g[cur][g[node][edge].rev].f -= df;
        }
        return df;
    }

public:
    void addEdge(int u, int v, int c){
        g[u].pb(Edge(v, g[v].size(), c, 0));
        g[v].pb(Edge(u, g[u].size() - 1, 0, 0));
    }

    int findMaxFlow(int u, int v){
        int maximumFlow = 0;
        while(bfs(u, v)){
            maximumFlow += increaseFlow(u, v);
        }
        return maximumFlow;
    }

    void printGraph(){
        rep(i, 0, 39){
            rep(j, 0, (int) g[i].size() - 1){
                cout << i << " " << g[i][j].v  << " " << g[i][j].c << endl;
            }
            cout << endl;
        }
    }

};

int main(){
    io
    freopen("software allocation.txt","r",stdin);
    string s;
    while(getline(cin, s)){
        rep(i, 0, 39){
            g[i].clear();
        }
        rep(i, 0, 9) ans[i] = -1;
        MaxFlow MF;
        do{
            int let = s[0] - 'A' + 12; //A starts at 12; 0: starting point; 1: sink
            int mark = s[1] - '0';
            MF.addEdge(0, let, mark);
            int i = 3;
            while(s[i] != ';'){
                int comp = s[i] - '0' + 2;
                MF.addEdge(let, comp, 1);
                i++;
            }
        }while(getline(cin, s) && !s.empty());
        rep(i, 2, 11){
            MF.addEdge(i, 1, 1);
        }
        int maximumFlow = MF.findMaxFlow(0, 1);
        if(maximumFlow > 10){
            cout << '!' << endl;
            continue;
        }
        bool mark = 0;
        rep(i, 0, g[0].size() - 1){
            if(g[0][i].c - g[0][i].f > 0){
                cout << '!' << endl;
                mark = 1;
                break;
            }
        }
        if(mark) continue;
        rep(i, 2, 11){
            rep(j, 0, g[i].size() - 1){
                if(g[i][j].f < 0){
                    ans[i - 2] = g[i][j].v;
                    break;
                }
            }
        }
        rep(i, 0, 9){
            if(ans[i] == -1){
                cout << '_';
                continue;
            }
            cout << (char) (ans[i] - 12 + 'A');
        }
        cout << endl;
    }
    return 0;
}

