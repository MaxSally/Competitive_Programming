//https://codeforces.com/problemset/problem/1276/B
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
#define ss second
#define ff first
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

const int N = 500005;
int n, m, a1, b1;
vi graph[N], mark;
vector<bool> visited;

void bfs(int x, int ignore, int mk){
    queue<int> q; q.push(x);
    visited[x] = 1;
    mark[x] += mk;
    while(!q.empty()){
        int u = q.front(); q.pop();
        foreach(v, graph[u]){
            if(visited[v] || v == ignore) continue;
            visited[v] = 1;
            mark[v] += mk;
            q.push(v);
        }
    }
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> n >> m >> a >> b;
        a1 = a; b1 = b;
        visited.clear();
        visited.resize(n + 1, 0);
        mark.clear();
        mark.resize(n + 1, 0);
        rep(i, 1, n){
            graph[i].clear();
        }
        rep(i, 1, m){
            int x, y; cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        bfs(b, a, 1);
        visited.clear();
        visited.resize(n + 1, 0);
        bfs(a, b, 2);
        int cnt1 = 0, cnt2 = 0;
        rep(i, 1, n){
            if(i == a || i == b) continue;
            if(mark[i] == 1){
                cnt1++;
            }else if(mark[i] == 2) {
                cnt2++;
            }
        }
        cout << 1LL * cnt1 * cnt2 << '\n';
    }
    return 0;
}
