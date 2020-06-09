//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2833
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

const int N = 100005;

struct triad{
    int u, v, weight;
};
vi graph[N];
triad edge[N * 10];
int n, m, a, dsu[N];

bool compare(triad x, triad y){
    return x.weight < y.weight;
}

int findSet(int u){
    return {dsu[u] == u? u: dsu[u] = findSet(dsu[u])};
}



pair<ll, int> kruskal(){
    int i = 0;
    ll res = 0;
    int cnt = 0;
    while(i < m && edge[i].weight < a && cnt < n){
        int x = findSet(edge[i].u);
        int y = findSet(edge[i].v);
        if(x != y){
            dsu[y] = x;
            res += 1LL * edge[i].weight;
            cnt++;
        }
        i++;
    }
    set<int> air;
    rep(i, 1, n){
        if(dsu[i] == i){
            air.insert(i);
        }
    }
    res += (ll) air.size() * a;
    return mp(res, (int)air.size());
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    rep(ii, 1, t){
        cin >> n >> m >> a;
        rep(i, 0, m - 1){
            cin >> edge[i].u >> edge[i].v >> edge[i].weight;
        }
        rep(i, 1, n){
            dsu[i] = i;
        }
        sort(edge, edge + m, compare);
        pair<ll, int> ans = kruskal();
        cout << "Case #" << ii << ": " << ans.ff << " " << ans.ss << endl;
    }
    return 0;
}
