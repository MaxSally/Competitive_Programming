//https://codeforces.com/problemset/problem/1093/D
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
#define mod 998244353
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

const int N = 300005;
int n, m;
vi graph[N];
int visited[N];

long long multiply(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

pll bfs(int k){
    queue<pii> q;
    q.push(mp(k, 0));
    visited[k] = 2;
    int odd = 0, even = 0;
    while(!q.empty()){
        int u = q.front().ff;
        int state = q.front().ss;
        q.pop();
        (state == 1? odd++:even++);
        foreach(v, graph[u]){
            if(visited[v] > 0){
                if((visited[v] + state) & 1){
                    continue;
                }else{
                    return mp(-1, -1);
                }
            }
            q.push(mp(v, (state + 1) & 1));
            visited[v] = (state == 0? 1: 2);
        }
    }
    return mp(even, odd);
}

ll count(){
    ll ans = 1LL;
    rep(i, 1, n){
        if(visited[i] > 0) continue;
        pii p = bfs(i);
        if(p == mp(-1, -1)){
            return 0;
        }
        ans = (ans * ((multiply(2LL, p.ff) + multiply(2LL, p.ss)) % mod)) % mod;
    }
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(i, 0, n){
            visited[i] = 0;
            graph[i].clear();
        }
        rep(i, 1, m){
            int x, y; cin >> x >> y;
            graph[x].pb(y); graph[y].pb(x);
        }
        cout << count() << "\n";
    }
    return 0;
}


