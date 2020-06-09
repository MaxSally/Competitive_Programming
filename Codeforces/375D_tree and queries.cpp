//https://codeforces.com/problemset/problem/375/D
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

struct triad{
    int l, r, id, k;
};

bool compare(triad a, triad b){
    int blockA = a.l/316;
    int blockB = b.l/316;
    if(blockA < blockB) return true;
    if(blockA > blockB) return false;
    if(blockA % 2 == 0) return a.r < b.r;
    return a.r > b.r;
}

const int N = 100005;
vi graph[N], a; //a la mang mau sau khi sort dfs
int n, m, dfsCnt = 0, in[N], out[N], f[N], cnt[N], c[N], ans[N];
vector<bool> visited;
vector<triad> q;

void dfs(int u){
    in[u] = ++dfsCnt;
    a.pb(c[u]);
    visited[u] = 1;
    rep(i, 0, (int)graph[u].size() - 1){
        int v = graph[u][i];
        if(visited[v]) continue;
        dfs(v);
    }
    out[u] = dfsCnt;
}

void add(int x){
    cnt[x]++;
    if(cnt[x] >= 0)
        f[cnt[x]]++;
}

void del(int x){
    if(cnt[x] >= 0)
        f[cnt[x]]--;
    cnt[x]--;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    mem(cnt, 0); mem(in, 0); mem(out, 0); mem(f, 0);
    rep(i, 1, n){
        cin >> c[i];
    }
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        graph[x].pb(y); graph[y].pb(x);
    }
    visited.resize(n + 1, 0);
    a.pb(-1);
    dfs(1);
    //debuga1(in, 1, n); debuga1(out, 1, n);
    int l = 1, r = 0;
    rep(ii, 1, m){
        int v, k; cin >> v >> k;
        q.pb({in[v], out[v], ii, k});
    }
    sort(q.begin(), q.end(), compare);
    rep(i, 0, m - 1){
        int leftV = q[i].l, rightV = q[i].r;
        //debug(leftV); debug(rightV);
        while(leftV < l){
            l--;
            add(a[l]);
        }
        while(leftV > l){
            del(a[l]);
            l++;
        }
        while(rightV < r){
            del(a[r]);
            r--;
        }
        while(rightV > r){
            r++;
            add(a[r]);
            //debuga1(cnt, 1, n);
        }
        //debug(l); debug(r);
        ans[q[i].id] = f[q[i].k];
    }
    rep(i, 1, m){
        cout  << ans[i] << endl;
    }
    return 0;
}

