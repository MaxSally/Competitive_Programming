//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
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

const int N = 2005;
int dp[N][N][6], a[N], b[N];

int modifyLCS(int i, int j, int kk){
    if(kk < 0) return -inf;
    if(i < 1 || j < 1) return 0;
    int &ans = dp[i][j][kk]; //too lazy, sleepy, etc, mainly etc to rewrite dp;
    if(ans != -1) return ans;
    ans = max(modifyLCS(i - 1, j, kk), modifyLCS(i, j - 1, kk));
    if(a[i] == b[j]){
        ans = max(ans, modifyLCS(i - 1, j - 1, kk) + 1);
    }
    ans = max(ans, modifyLCS(i - 1, j - 1, kk - 1) + 1);
    return ans;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, m, k; cin >> n >> m >> k;
    rep(i, 1, n){
        cin >> a[i];
    }
    rep(i, 1, m){
        cin >> b[i];
    }
    mem(dp, -1);
    /*rep(i, 1, n){
        rep(j, 1, m){
            rep(kk, 1, k){
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                if(a[i] == b[j]){
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
                }
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
            }
        }
    }*/
    cout << modifyLCS(n, m, k);
    return 0;
}
