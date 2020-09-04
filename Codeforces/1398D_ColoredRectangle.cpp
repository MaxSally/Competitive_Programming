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

const int N = 205;
ll r[N], g[N], b[N];
ll dp[N][N][N];
int n, n1, n2;

bool compare(int x, int y){
    return x > y;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> n1 >> n2;
    rep(i, 0, n - 1){
        cin >> r[i];
    }
    rep(i, 0, n1 - 1){
        cin >> g[i];
    }
    rep(i, 0, n2 - 1){
        cin >> b[i];
    }
    sort(r, r + n, compare);
    sort(g, g + n1, compare);
    sort(b, b + n2, compare);
    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n1){
            rep(k, 0, n2){
                if(i + j + k < 2)continue;
                ll temp = 0;
                if(i > 0 && j > 0) {
                    temp = max(temp, dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
                }
                if(j > 0 && k > 0){
                    temp = max(temp, dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
                }
                if(i > 0 && k > 0){
                    temp = max(temp, dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);
                }
                dp[i][j][k] = temp;
                ans = max(ans, temp);
            }
        }
    }
    cout << ans;
    return 0;
}
