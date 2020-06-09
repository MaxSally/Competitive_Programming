//https://codeforces.com/contest/456/problem/E
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

const int N = 300005;
int n, m, q;
int parent[N];
int dp[3][N];
vector<bool> visited;
vi graph[N];
int diameter[N];
vi group[N];

int findSet(int u){
    return (parent[u] == u? u: parent[u] = findSet(parent[u]));
}

void joinSet(int u, int v){
    int a = findSet(u);
    int b = findSet(v);
    parent[a] = b;
}

void dfs(int s){
    visited[s] = 1;
    for(int v: graph[s]){
        if(visited[v]) continue;
        dfs(v);
        if(dp[1][v] + 1 >= dp[1][s]){
            dp[2][s] = dp[1][s];
            dp[1][s] = dp[1][v] + 1;
        }else if(dp[1][v] + 1 >= dp[2][s]){
            dp[2][s] = dp[1][v] + 1;
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    mem(diameter, 0);
    rep(i, 1, n){
        parent[i] = i;
    }
    rep(i, 1, m){
        int u, v; cin >> u >> v;
        joinSet(u, v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    visited.resize(n + 1, 0);
    rep(i, 1, n){
        if(!visited[i]){
            dfs(i);
        }
    }
    rep(i, 1, n){
        int a = findSet(i);
        //debug(a);
        group[a].pb(i);
    }
    //debuga1(group[19], 0, (int)group[19].size() - 1);
    rep(i, 1, n){
        int maxN = 0;

        rep(j, 0, (int)group[i].size() - 1){
            int node = group[i][j];
            maxN = max(maxN, dp[1][node] + dp[2][node]);
        }
        diameter[i] = maxN;
    }
    while(q--){
        /*cout << "diameter" << " ";
        debuga1(diameter, 1, n);
        cout << "parent" << " ";
        debuga1(parent, 1, n);*/
        int x; cin >> x;
        if(x == 1){
            int u; cin >> u;
            int a = findSet(u);
            cout << diameter[a] << endl;
        }else{
            int u, v; cin >> u >> v;
            int c = findSet(v);
            int d = findSet(u);
            if(c == d) continue;
            int a = diameter[d];
            int b = diameter[c];
            diameter[c] = max(max(b, a), (b + 1)/2 + (a + 1)/2 + 1);
            joinSet(u, v);
        }
    }
    return 0;
}

