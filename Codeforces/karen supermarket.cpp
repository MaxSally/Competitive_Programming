//https://codeforces.com/contest/815/problem/C

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
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
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

const int N = 5005;
int n, b;
pll item[N];
vi graph[N];
ll dp[N][N][2];
int sub[N], coupon[N];


void dfs(int root){
    dp[root][1][1] = item[root].second;
    dp[root][0][0] = 0ll;
    dp[root][1][0] = item[root].first;
    sub[root] = 1;
    rep(i, (int) graph[root].size()){
        int child = graph[root][i];
        if(child != coupon[root]){
            dfs(child);
            rrep(a, sub[root]){
                rrep(b, sub[child]){
                    dp[root][a + b][1] = min(dp[root][a + b][1], min(dp[child][b][0], dp[child][b][1]) + dp[root][a][1]);
                    dp[root][a + b][0] = min(dp[root][a + b][0], dp[child][b][0] + dp[root][a][0]);

                }
            }
            sub[root] += sub[child];
        }
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> b;
    fo(i, 1, n + 1, 1){
        cin >> item[i].first >> item[i].second;
        item[i].second = item[i].first - item[i].second;
        if(i > 1){
            cin >> coupon[i];
            graph[coupon[i]].pb(i);
        }
    }
    fo(i, 1, n + 1, 1){
        rep(j, n + 1){
            dp[i][j][0] = dp[i][j][1] = (ll) inf;
        }
    }
    dfs(1);
    int ans = 0;
    rep(i, n + 1){
        if(min(dp[1][i][0], dp[1][i][1]) <= b){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}

