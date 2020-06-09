//https://codeforces.com/problemset/problem/543/B
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

const int N = 3005;
int n, m, dist[N][N];
bool visited[N];
vi a[N];

void findMinDistAtK(int k){
    mem(visited, 0);
    queue<int> q;
    visited[k] = 1;
    dist[k][k] = 0;
    q.push(k);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        foreach(v, a[u]){
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
                dist[k][v] = dist[k][u] + 1;
            }
        }
    }
}



int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    int s1, t1, l1, s2, t2, l2; cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    rep(i, 1, n){
        findMinDistAtK(i);
    }

    int minDist = inf;
    if(dist[s1][t1] <= l1 && dist[s2][t2] <= l2){
        minDist = dist[s1][t1] + dist[s2][t2];
    }
    rep(i, 1, n){
        rep(j, 1, n){
            int dist1 = dist[s1][i] + dist[i][j] + dist[j][t1];
            int dist2 = dist[s2][i] + dist[i][j] + dist[j][t2];
            int dist3 = dist[s1][j] + dist[j][i] + dist[i][t1];
            int dist4 = dist[s2][j] + dist[j][i] + dist[i][t2];
            if(dist1 > l1 && dist3 > l1) continue;
            if(dist2 > l2 && dist4 > l2) continue;
            minDist = min(minDist, min(min(dist1 + dist2, dist3 + dist2), min(dist1 + dist4, dist3 + dist4)) - dist[i][j]);
        }
    }

    cout << (minDist == inf? -1: m - minDist);
    return 0;
}
