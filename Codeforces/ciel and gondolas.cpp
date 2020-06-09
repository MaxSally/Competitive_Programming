//https://codeforces.com/contest/321/problem/E
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
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fo(i, l, r, 1) cout << a[i] << " "; cout << endl
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

const int N = 4005;
const int K = 805;
const int inf = 1e9 + 7;
int dp[K][N], cost[N][N], sum[N][N], mat[N][N], n, k;

inline int getInt(){
    char c;
    do{
        c = getchar();
    }while(c < '0' || c > '9');
    return c - '0';
}

int main(){
    //io
    freopen("input.txt","r",stdin);
    //int t; SCD(t);
    //while(t--){
    /*rep(i, 1, k){
        rep(j, 1, n){
            dp[i][j] = 0;
            cost[i][j] = 0;
            mat[i][j] = 0;
            sum[i][j] = 0;
        }
    }*/
    mem(dp, 63);
    SCD(n);
    SCD(k);
    rep(i, 1, n){
        rep(j, 1, n){
            mat[i][j] = mat[i - 1][j] - mat[i - 1][j - 1] + mat[i][j - 1] + getInt();
        }
    }
    rep(i, 1, n){
        rep(j, i, n){
            sum[i][j] = mat[j][j] - mat[i - 1][j] - mat[j][i - 1] + mat[i - 1][i - 1];
            sum[i][j] >>= 1;
        }
    }
    rep(i, 1, n){
        dp[1][i] = sum[1][i];
        cost[1][i] = 0;
    }
    rep(i, 2, k){
        cost[i][n + 1] = n;
        rrep(j, n, i){
            rep(h, cost[i - 1][j], cost[i][j + 1]){
                int x = dp[i - 1][h] + sum[h + 1][j];
                if(dp[i][j] > x){
                    dp[i][j] = x;
                    cost[i][j] = h;
                }
            }
        }
    }
    printf("%d ", dp[k][n]);

    return 0;
}

