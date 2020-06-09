//https://codeforces.com/problemset/problem/682/C

/*
* Author : Max Nguyen
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
#define fo(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rfor(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) fo(i, 0, j, 1)
#define rrep(i, j) rfor(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
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
int n;
ll dist[N], a[N];
bool mark[N], visited[N];
vpll graph[N];

void dfsDist(int node){
    visited[node] = 1;
    rep(i, (int) graph[node].size()){
        ll b = graph[node][i].first;
        ll c = graph[node][i].second;
        if(visited[b]) continue;
        dist[b] = max(c, dist[node] + c);

        if(dist[b] > a[b]){
           // cout << b << " " << dist[b] << endl;
            mark[b] = 1;
        }
        dfsDist(b);
    }
}

void dfsMark(int node){
    visited[node] = 1;
    rep(i, (int) graph[node].size()){
        ll b = graph[node][i].first;
        ll c = graph[node][i].second;
        if(visited[b]) continue;
        mark[b] |= mark[node];
        //cout << b << " " << mark[b] << endl;
        dfsMark(b);
    }
}


int main(){
    io
    //freopen("input.txt","r",stdin);
    mem(dist, 0);
    mem(mark, 0);
    mem(visited, 0);
    cin >> n;
    rep(i, n){
        cin >> a[i + 1];
    }
    rep(i, n - 1){
        int b, c;
        cin >> b >> c;
        graph[i + 2].pb(mp(b, c));
        graph[b].pb(mp(i + 2, c));
    }
    dfsDist(1);
    mem(visited, 0);
    dfsMark(1);
    int cnt = 0;
    rep(i, N){
        cnt += mark[i + 1];
        //cout << (mark[i]? i:0) << endl;
    }
    cout << cnt;
    return 0;
}

// dist v = dist(u) + w, w
// mark[v] |= mark[u];
