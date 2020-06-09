//https://codeforces.com/problemset/problem/812/E
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
#define foreach(i, a) for(auto i: a)
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
int a[N];
MPII green, red;
bool color[N], visited[N]; //1: green; 0 : red
queue<int> q;

void bfs(){
    while(q.size()){
        int u = q.front(); q.pop();
        foreach(v, graph[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = 1;
            color[v] = !color[u];
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, cntB = 0; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n){
        int x; cin >> x;
        graph[x].pb(i);
        graph[i].pb(x);
    }
    mem(visited, 0); mem(color, 0);
    rep(i, 2, n){
        if((int)graph[i].size() == 1){
            q.push(i);
            visited[i] = 1;
            color[i] = 1;
        }
    }
    bfs();
    int sum = 0;
    rep(i, 1, n){
        if(color[i]){
            cntB++;
            sum ^= a[i];
            //green[a[i]]++;
        }else{
            red[a[i]]++;
        }
    }
    int cntR = n - cntB;
    ll ans = 0;
    if(sum == 0){
        rep(i, 1, n){
            if(color[i]){
                ans += red[a[i]];
            }
        }
        ans += (1LL * cntB * (cntB - 1)/2) + (1LL * cntR * (cntR - 1)/2);
    }else{
        rep(i, 1, n){
            if(color[i]){
                ans += red[sum ^ a[i]];
            }
        }
    }
    cout << ans;
    return 0;
}