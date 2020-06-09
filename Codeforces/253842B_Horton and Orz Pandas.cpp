//https://codeforces.com/gym/253842/problem/B
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

/*
binary search x
b - a * x = c
sort based off c
kruskal
*/

struct point{
    int y, a, b;
};
struct edge{
    int x, y, a, b;
};

const int N = 10005;
int parent[N], n, m;
vector<point> graph[N];
vector<edge> lst;

bool compare(edge a, edge b){
    return (1LL * a.b * b.a) > (1LL * b.b * a.a);
}

int findSet(int u){
    return (u == parent[u]? u: parent[u] = findSet(parent[u]));
}

bool unionSet(int u, int v){
    int parU = findSet(u);
    int parV = findSet(v);
    if(parU != parV){
        parent[parU] = parV;
        return 1;
    }
    return 0;
}

void kruskal(){
    ll totalA = 0, totalB = 0;
    vii leftOver;
    foreach(e, lst){
        int x = e.x, y = e.y, a = e.a, b = e.b;
        //debug(x); debug(y);
        if(unionSet(x, y)){
            totalA += a;
            totalB += b;
        }else{
            leftOver.pb(mp(a, b));
        }
    }
    foreach(v, leftOver){
        if(1.0 * totalB/totalA < 1.0 * v.ss/v.ff){
            totalB += v.ss;
            totalA += v.ff;
        }else{
            break;
        }
    }
    cout << fixed << setprecision(9) << 1.0 * totalB/ totalA;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(ii, 1, m){
        int x, y, a, b; cin >> x >> y >> a >> b;
        graph[x].pb({y, a, b});
        graph[y].pb({x, a, b});
        lst.pb({x, y, a, b});
    }
    rep(i, 1, n){
        parent[i] = i;
    }
    sort(all(lst), compare);
    kruskal();
    return 0;
}
