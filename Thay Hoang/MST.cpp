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

struct triad{
    int u, v, cost;
};

const int N = 100005;
map<int, ll> graph[N];
int parent[N];
int n;

struct compareTriad{
    bool operator()(triad &x, triad &y){
        return x.cost > y.cost;
    }
};


priority_queue<triad, vector<triad>, compareTriad > pq;

int findSet(int s){
    return (s == parent[s]? s: parent[s] = findSet(parent[s]));
}

bool unionSet(int s, int v){
    int ds = findSet(s);
    int dv = findSet(v);
    if(ds != dv){
        parent[ds] = dv;
        return 1;
    }
    return 0;
}

int main(){
    io;
    freopen("MST.INP", "r", stdin);
    freopen("MST.OUT", "w", stdout);
    int m;
    cin >> n >> m;
    rep(i, 1, n){
        parent[i] = i;
    }
    rep(i, 1, m){
        int x, y, cost; cin >> x >> y >> cost;
        graph[x][y] = min(graph[x][y], 1LL*cost);
        pq.push({x, y, cost});
    }
    ll totalCost = 0;
    while(!pq.empty()){
        int u = pq.top().u, v = pq.top().v, cost = pq.top().cost;
        pq.pop();
        //debug(cost);
        if(unionSet(u, v)){
            totalCost += cost;
        }
    }
    int parentNode = findSet(1);
    rep(i, 2, n){
        int curParentNode = findSet(i);
        if(curParentNode != parentNode){
            cout << "DISCONNECTED";
            return 0;
        }
    }
    cout << totalCost;
    return 0;
}

