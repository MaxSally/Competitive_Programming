//https://codeforces.com/problemset/problem/519/E
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
vi graph[N];
int n, b[20][N], h[N], d[N];

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
    if(u == v){
        return u;
    }
    rrep(i, (int)log2(n), 0){
        if(b[i][u] != b[i][v]){
            u = b[i][u];
            v = b[i][v];
        }
    }
    return b[0][u];
}

int dfs(int s, vector<bool> &visited){
    visited[s] = 1;
    int ans = 1;
    for(int a: graph[s]){
        if(visited[a]) continue;
        h[a] = h[s] + 1;
        b[0][a] = s;
        ans += dfs(a, visited);
    }
    d[s] = ans;
    //cout << s << " " << ans << endl;
    return ans;
}

void prepare(int s){
    vector<bool> visited(n, 0);
    visited[s] = 1;
    rep(i, 1, n){
        b[0][i] = -1;
    }
    h[s] = 0;
    d[s] = dfs(s, visited);
    rep(i, 1, (int)log2(n)){
        rep(j, 1, n){
            b[i][j] = b[i - 1][b[i - 1][j]];
        }
    }
}

int findRoom(int u, int v){
    if(u == v) return n;
    if(h[u] < h[v]){
        swap(u, v);
    }
    int a = LCA(u, v);
    int t = h[u] + h[v] - 2*h[a];
    if(t % 2){
        return 0;
    }
    t /= 2;
    t--;
    if(h[u] == h[v]){
        rrep(i, (int)log2(n), 0){
            if(b[i][u] != b[i][v]){
                u = b[i][u];
                v = b[i][v];
            }
        }
        //debug(d[u]);
        //debug(d[v]);
        return (n - d[u] - d[v]);
    }
    rrep(i, (int)log2(t), 0){
        if((t >> i) & 1){
            u = b[i][u];
        }
    }
    //debug(a);
    //debug(u);
    //debuga1(d, 1, n);
    //debug(d[b[0][u]]);
    return (d[b[0][u]] - d[u]);
}

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n;
    mem(h, 0);
    mem(d, 0);
    rep(i, 0, 19){
        mem(b[i], 0);
    }
    rep(i, 0, N - 1){
        graph[i].clear();
    }
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int q; cin >> q;
    prepare(1);
    while(q--){
        int u, v; cin >> u >> v;
        int ans = findRoom(u, v);
        cout << ans << endl;
    }
    return 0;
}

