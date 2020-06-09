//https://codeforces.com/problemset/problem/793/D
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

const int N = 85;
int n, k, m;
int dist[N][N], dp[N][N][N][2];

int findDP(int left, int right, int cnt, bool state){
    if(dp[left][right][cnt][state] != -1 || cnt == k){
        return dp[left][right][cnt][state];
    }
    int minN = inf;
    rep(i, left + 1, right - 1){
        if(!state && dist[left][i] != inf){
            minN = min(minN, min(findDP(left, i, cnt + 1, 1) , findDP(i, right, cnt + 1, 0)) + dist[left][i]);
        }
        if(state && dist[right][i] != inf){
            minN = min(minN, min(findDP(left, i, cnt + 1, 1) , findDP(i, right, cnt + 1, 0)) + dist[right][i]);
        }
    }
    dp[left][right][cnt][state] = minN;
    //debug(minN);
    return minN;
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> k >> m;
    rep(i, 0, n + 1){
        rep(j, 0, n + 1){
            dist[i][j] = ((i == 0 || j == 0 || i == n + 1 || j == n + 1) ? 0: inf);
            rep(kk, 0, k - 1){
                dp[i][j][kk][0] = dp[i][j][kk][1] = -1;
            }
            dp[i][j][k][0] = dp[i][j][k][1] = 0;
        }
    }
    rep(i, 1, m){
        int u, v, c; cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
    }
    int ans = min(findDP(0, n + 1, 0, 0), findDP(0, n + 1, 0, 1));
    cout << (ans == inf? -1: ans);
    return 0;
}
