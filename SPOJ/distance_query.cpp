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
int dMax[20][N], dMin[20][N], b[20][N], h[N], n;
vii graph[N];

pair<int,int> LCA(int u, int v){
    if(h[u] < h[v]){
        swap(u, v);
    }
    int maxN = 0, minN = inf;
    int t = h[u] - h[v];
    rep(i, 0, (int)log2(t)){
        if((t >> i) & 1){
            maxN = max(maxN, dMax[i][u]);
            minN = min(minN, dMin[i][u]);
            u = b[i][u];
        }
    }
    if(u == v) return {minN, maxN};
    rrep(i, (int)log2(n), 0){
        if(b[i][u] != b[i][v]){
            maxN = max(maxN, dMax[i][u]);
            minN = min(minN, dMin[i][u]);
            maxN = max(maxN, dMax[i][v]);
            minN = min(minN, dMin[i][v]);
            u = b[i][u];
            v = b[i][v];
            //cout << u << " " << v << " " << maxN << " " << minN << endl;
        }
    }
    maxN = max(maxN, dMax[0][u]);
    minN = min(minN, dMin[0][u]);
    maxN = max(maxN, dMax[0][v]);
    minN = min(minN, dMin[0][v]);
    return {minN, maxN};
}

/*pair<int,int> parent_children(int parent, int child){
    int t = h[child] - h[parent];
    int maxN = 0, minN = inf;
    rrep(i, (int)log2(t), 0){
        maxN = max(dMax[i][child])
    }
}*/

void dfs(int s, vector<bool> &visited){
    visited[s] = 1;
    for(pair<int,int> a: graph[s]){
        if(visited[a.first]) continue;
        b[0][a.first] = s;
        h[a.first] = h[s] + 1;
        dMin[0][a.first] = dMax[0][a.first] = a.second;
        dfs(a.first, visited);
    }
}

void prepare(int s){
    vector<bool> visited(n + 1, 0);
    rep(i, 1, n){
        b[0][i] = -1;
    }
    h[s] = 0;
    dfs(s, visited);
    rep(i, 1, (int) log2(n)){
        rep(j, 1, n){
            b[i][j] = b[i - 1][b[i -1][j]];
            dMax[i][j] = max(dMax[i - 1][j], dMax[i - 1][b[i - 1][j]]);
            dMin[i][j] = min(dMin[i - 1][j], dMin[i - 1][b[i - 1][j]]);
        }
    }
}

int main(){
    io;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    rep(i, 0, n){
        graph[i].clear();
    }
    rep(i, 0, 19){
        mem(b[i], 0);
    }
    mem(h, 0);
    rep(i, 1, n - 1){
        int x, y, z; cin >> x >> y >> z;
        graph[x].pb({y, z});
        graph[y].pb({x, z});
    }
    prepare(1);
    //Flag(1);
    //debuga1(dMax, 1, n);
    //debuga1(dMin, 1, n);
    //debuga1(h, 1, n);
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        pair<int,int> a = LCA(u, v);
        //debug(a);
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}

