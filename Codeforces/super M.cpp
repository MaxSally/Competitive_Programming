//https://codeforces.com/contest/592/problem/D
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

const int N = 123460;
vi graph[N];
bool check[N], visited[N];
int n, m, h[N], cntRoad, h1[N];
bool mCity[N];


int dfsRemoveNode(int s){
    visited[s] = 1;
    int cnt = 0;
    if(mCity[s]) cnt++;
    for(int v : graph[s]){
        if(visited[v]) continue;
        cnt += dfsRemoveNode(v);
    }
    if(cnt == 0){
        check[s] = 0;
    }
    return cnt;
}

void dfsFindStartingNode(int s){
    visited[s] = 1;
    for(int v: graph[s]){
        if(visited[v] || !check[v]) continue;
        h[v] = h[s] + 1;
        cntRoad++;
        dfsFindStartingNode(v);
    }
}

void dfsFindDiameter(int s){
    visited[s] = 1;
    for(int v: graph[s]){
        if(visited[v] || !check[v]) continue;
        h1[v] = h1[s] + 1;
        dfsFindDiameter(v);
    }
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    fill(check, check + n + 1, 1);
    fill(h, h + n + 1, -1);
    fill(h1, h1 + n + 1, -1);
    rep(i, 1, n - 1){
        int u, v; cin >>u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int ind = inf;
    rep(i, 1, m){
        int x; cin >> x;
        ind = min(ind, x);
        mCity[x] = 1;
    }
    mem(visited, 0);
    int a = dfsRemoveNode(ind);
    mem(visited, 0);
    h[ind] = 0;
    dfsFindStartingNode(ind);
    int startP = inf, valueSP = -1;
    rep(i, 1, n){
        if(h[i] > valueSP){
            startP = i;
            valueSP = h[i];
        }
    }
    mem(visited, 0);
    h1[startP] = 0;
    dfsFindDiameter(startP);
    int endP = inf, valueEP = -1;
    rep(i, 1, n){
        if(h1[i] > valueEP){
            endP = i;
            valueEP = h1[i];
        }
    }
    //debug(startP); debug(endP);
    cout << min(startP, endP) << endl;
    cout << 2*cntRoad - valueEP;
    return 0;
}

