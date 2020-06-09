//https://codeforces.com/problemset/problem/342/E
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
int n, m, b[20][2 * N], h[N], curH[N], in[N], out[N]; //
vi graph[N], toUpdate, lis;

void bfs(){
    queue<int> q;
    vi d(n + 1, 0);
    rep(i, 0, (int)toUpdate.size() - 1){
        q.push(toUpdate[i]);
        d[toUpdate[i]] = 1;
    }
    toUpdate.clear();
    while((int)q.size()){
        int u = q.front(); q.pop();
        rep(i, 0, (int)graph[u].size() - 1){
            int v = graph[u][i];
            if(!d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    rep(i, 1, n){
        curH[i] = min(curH[i], d[i] - 1);
    }
}

void initiateTree(int u, int pre){
    in[u] = out[u] = (int)lis.size();
    lis.pb(h[u]);
    rep(i, 0, (int)graph[u].size() - 1){
        int v = graph[u][i];
        if(v != pre){
            h[v] = h[u] + 1;
            initiateTree(v, u);
            out[u] = (int)lis.size();
            lis.pb(h[u]);
        }
    }
}

void sparseTable(){
    int sz = (int)lis.size();
    int k = log2(sz);
    rep(i, 0, sz - 1){
        b[0][i] = lis[i];
    }
    rep(i, 1, k){
        rep(j, 0, sz - (1 << i)){
            b[i][j] = min(b[i - 1][j], b[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int findLCA(int l, int r){ // find minimum distance on sparse table
    int k = log2(r - l + 1);
    return min(b[k][l], b[k][r - (1 << k) + 1]);
}

int findDis(int u, int v){
    return h[u] + h[v] - 2 * findLCA(min(in[u], in[v]), max(out[u], out[v]));
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    mem(in, 0);
    mem(out, 0);
    rep(i, 1, n - 1){
        int u, v; cin >> u >> v;
        graph[u].pb(v); graph[v].pb(u);
    }
    initiateTree(1, -1);
    sparseTable();
    toUpdate.pb(1);
    fill(curH, curH + n + 1, inf);
    while(m--){
        int t, v; cin >> t >> v;
        if(t == 1){
            toUpdate.pb(v);
            if((int)toUpdate.size() >= sqrt(N)){
                bfs();
            }
        }else{
            int res = curH[v];
            rep(i, 0, (int)toUpdate.size() - 1){ //Check length of toUpdate
                int k = toUpdate[i];
                res = min(res, findDis(v, k));
            }
            cout << res << endl;
        }
    }
    return 0;
}
