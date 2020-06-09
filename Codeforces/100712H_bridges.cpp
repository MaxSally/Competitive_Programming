//https://codeforces.com/gym/100712/attachments
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
int n, m, num[N], low[N], Time = 0, connected[N], cntConnected = 0, criticalEdge = 0;
vi graph[N];
vi newGraph[N];
bool visited[N];
set<pii> lstCriticalEdge;

void visit(int u, int p){
    low[u] = num[u] = ++Time;
    foreach(v, graph[u]){
        if(v == p) continue;
        if(num[v] != 0){
            low[u] = min(low[u], num[v]);
        }else{
            visit(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[v]){
                criticalEdge++;
                lstCriticalEdge.insert(mp(u, v));
                lstCriticalEdge.insert(mp(v, u));
            }

        }
    }
}

void dfs(int u){
    visited[u] = 1;
    connected[u] = cntConnected;
    foreach(v, graph[u]){
        if(visited[v]) continue;
        if(lstCriticalEdge.find(mp(u, v)) == lstCriticalEdge.end()){
            dfs(v);
        }
    }
}

int findDiameterTree(){
    queue<pii> q;
    q.push(mp(1, 0));
    int u, p;
    mem(visited, 0);
    visited[1] = 1;
    while(!q.empty()){
        u = q.front().ff;
        q.pop();
        foreach(v, newGraph[u]){
            if(visited[v]) continue;
            q.push(mp(v, u));
            visited[v] = 1;
        }
    }
    q.push(mp(u, 0));
    mem(visited, 0);
    visited[u] = 1;
    while(!q.empty()){
        u = q.front().ff;
        p = q.front().ss;
        q.pop();
        foreach(v, newGraph[u]){
            if(visited[v]) continue;
            q.push(mp(v, p + 1));
            visited[v] = 1;
        }
    }
    return p;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    rep(ii, 1, t){
        mem(low, 0);
        mem(num, 0);
        mem(connected, 0);
        lstCriticalEdge.clear();
        Time = 0;
        criticalEdge = 0;
        cntConnected = 1;
        mem(visited, 0);
        cin >> n >> m;
        rep(i, 1, n){
            graph[i].clear();
            newGraph[i].clear();
        }
        rep(i, 1, m){
            int x, y; cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }

        visit(1, 1);

        rep(i, 1, n){
            if(!visited[i]){
                dfs(i);
                cntConnected++;
            }
        }
        set<pii>::iterator it;
        for(it = lstCriticalEdge.begin(); it != lstCriticalEdge.end(); it++){
            int u = (*it).ff, v = (*it).ss;
            newGraph[connected[u]].pb(connected[v]); // do not need the other one since lstCriticalEdge has two (u, v) and (v, u)
            //newGraph[v].pb(u);
        }
        int ans = findDiameterTree();
        //debug(ans);
        cout << criticalEdge - ans << endl;
    }
    return 0;
}
