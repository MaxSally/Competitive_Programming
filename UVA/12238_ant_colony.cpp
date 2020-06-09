//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3390
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

const int N = 100005;
int h[N], b[20][N], n;
ll d[N];
vector<pair<int,int> > graph[N];

int LCA(int u, int v){
    if(h[u] < h[v]){
        swap(u, v);
    }
    int t = h[u] - h[v];
    rep(i, 0, (int)log2(t)){
        if((t >> i) & 1){
            u = b[i][u];
        }
    }
    if(u == v) return u;
    rrep(i, (int)log2(n), 0){
        if(b[i][u] != b[i][v]){
            u = b[i][u];
            v = b[i][v];
        }
    }
    return b[0][u];
}

void bfs(int s){
    queue<int> q; q.push(s);
    vector<bool> visited(n, 0);
    h[s] = 0;
    rep(i, 0, n - 1){
        b[0][i] = -1;
    }
    visited[s] = 1;
    d[s] = 0LL;
    while(q.size()){
        int u = q.front(); q.pop();
        for(pair<int,int> a: graph[u]){
            if(visited[a.first]) continue;
            visited[a.first] = 1;
            q.push(a.first);
            b[0][a.first] = u;
            d[a.first] = d[u] + 1LL*a.second;
            h[a.first] = h[u] + 1;
        }
    }
    int len = (int)log2(n);
    rep(i, 1, len){
        rep(j, 0, n - 1){
            b[i][j] = b[i - 1][b[i - 1][j]];
        }
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    while(true){
        cin >> n; if(n == 0)break;
        rep(i, 0, n - 1){
            graph[i].clear();
        }
        mem(d, 0LL);
        rep(i, 0, 19){
            mem(b[i], 0);
        }
        mem(h, 0);
        //debug(n);
        rep(i, 1, n - 1){
            int a, l; cin >> a >> l;
            graph[i].pb({a, l});
            graph[a].pb({i, l});
        }
        /*rep(i, 0, n - 1){
            debug(i);
            rep(j, 0, (int)graph[i].size() - 1){
                cout << graph[i][j].first << " " << graph[i][j].second << endl;
            }
            cout << endl;
        }*/
        bfs(0);
        int q; cin >> q;
        while(q--){
            int u, v; cin >> u >> v;
            int ancestor = LCA(u, v);
            cout << d[u] + d[v] - 2LL*d[ancestor];
            if(q > 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

