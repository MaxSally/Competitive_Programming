//https://open.kattis.com/contests/asiasg18-prelim-open/problems/caveexploration
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
int n, m, num[N], low[N], Time = 0;
vi graph[N];
set<pii> criticalEdge;

void findCriticalEdge(int u, int p){
    int numChild = 0;
    low[u] = num[u] = ++Time;
    foreach(v, graph[u]){
        if(v == p) continue;
        if(num[v] != 0){
            low[u] = min(low[u], num[v]);
        }else{
            findCriticalEdge(v, u);
            numChild++;
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[v]){
                criticalEdge.insert(mp(u, v));
                criticalEdge.insert(mp(v, u));
            }
        }
    }
}

int visit(){
    vector<bool> visit(n, 0);
    stack<int> s;
    s.push(0);
    int cnt = 0;
    visit[0] = 1;
    while(!s.empty()){
        cnt++;
        int u = s.top(); s.pop();
        foreach(v, graph[u]){
            if(visit[v]) continue;
            if(criticalEdge.find(mp(u, v)) == criticalEdge.end() && criticalEdge.find(mp(v, u)) == criticalEdge.end()){
                s.push(v);
                visit[v] = 1;
            }
        }
    }
    return cnt;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    findCriticalEdge(0, 0);
    cout << visit();
    return 0;
}
