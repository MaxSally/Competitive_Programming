//https://atcoder.jp/contests/arc078/tasks/arc078_b
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
bool visited[N];
int h[N], n, path[N];

int bfs(){
    queue<int> q;
    q.push(1);
    mem(h, 0);
    mem(visited, 0);
    visited[1] = 1;
    visited[n] = 1;
    while((int)q.size()){
        int u = q.front(); q.pop();
        foreach(v, graph[u]){
            if(visited[v]) continue;
            visited[v] = 1;
            q.push(v);
            h[v] = h[u] + 1;
            path[v] = u;
        }
    }
    foreach(v, graph[n]){
        if(h[v] == 0) continue;
        h[n] = h[v] + 1;
        path[n] = v;
    }
    return h[n];
}

void secondBFS(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while((int)q.size()){
        int u = q.front(); q.pop();
        foreach(v, graph[u]){
            if(visited[v]) continue;
            visited[v] = 1;
            q.push(v);
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n;
    if(n == 2){
        cout << "Snuke";
        return 0;
    }
    rep(i, 1, n - 1){
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int dist = bfs();
    int step = (dist - 1)/2;
    int cur = n;
    mem(visited, 0);
    //debug(step);
    while(step--){
        cur = path[cur];
    }
    //debug(cur);
    visited[cur] = 1;
    int extra = 1;
    if(cur != 1) extra++;
    secondBFS();
    int black = 0;
    rep(i, 1, n){
        black += visited[i];
    }
    //debug(dist); debug(black);
    black = black - extra;
    //debug(black);
    int white = n - black - 2;
    //debug(black); debug(white);
    cout << (black > white? "Fennec": "Snuke");
    return 0;
}

