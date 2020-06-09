//https://open.kattis.com/contests/q8iz3g/problems/allpairspath
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
#define inf (long long) (1e16 + 7)
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

const int N = 155;
ll cost[N][N];

void floydWarshall(int n){
    rep(k, 0, n - 1){
        rep(i, 0, n - 1){
            if(cost[i][k] == inf)continue;
            rep(j, 0, n - 1){
                if(cost[k][j] == inf) continue;
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    while(true){
        int n, m, q; cin >> n >> m >> q;
        if(n == 0 && m == 0 && q == 0) return 0;
        rep(i, 0, n - 1){
            rep(j, 0, n - 1){
                if(i == j) cost[i][j] = 0;
                else cost[i][j] = inf;
            }
        }
        rep(i, 1, m){
            int x, y, w; cin >> x >> y >> w;
            cost[x][y] = min(cost[x][y], 1LL* w);
        }
        floydWarshall(n);
        rep(ii, 1, q){
            int u, v; cin >> u >> v;
            if(cost[u][v] == inf){
                cout << "Impossible\n";
            }else{
                bool cc = false;
                rep(i, 0, n - 1) {
                    if(cost[i][i] < 0 && cost[u][i] != inf && cost[i][v] != inf) {
                        cc = true;
                        break;
                    }
                }
                if(cc)
                    cout << "-Infinity\n";
                else
                    cout << cost[u][v] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
